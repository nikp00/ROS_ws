#!/usr/bin/python3
"""
sudo apt install libzbar0
sudo apt install python3-pyaudio
sudo apt install tesseract-ocr libtesseract-dev
pip3 install pyzbar
pip3 install pytesseract
pip3 install SpeechRecognition
"""



import roslib
import time
import rospy
import speech_recognition as sr

class SpeechTranscriber:
    def __init__(self):
        #rospy.init_node('speech_transcriber', anonymous=True)
        
        # The documentation is here: https://github.com/Uberi/speech_recognition

        # The main interface to the speech recognition engines
        self.sr = sr.Recognizer()
        
        # These are the methods that are available to us for recognition.
        # Please note that most of them use an internet connection and currently they are using
        # a default API user/pass, so there are restrictions on the number of requests we can make.
        # recognize_bing(): Microsoft Bing Speech
        # recognize_google(): Google Web Speech API
        # recognize_google_cloud(): Google Cloud Speech - requires installation of the google-cloud-speech package
        # recognize_houndify(): Houndify by SoundHound
        # recognize_ibm(): IBM Speech to Text
        # recognize_sphinx(): CMU Sphinx - requires installing PocketSphinx
        # recognize_wit(): Wit.ai
        
        # An interface to the default microphone
        self.mic = sr.Microphone()


        self.affirmative_answers = ["yes", "i have", "i do"]
        self.negative_answers = ["no", "not", "i don't"]
        self.doctors = ["green", "red", "blue", "black"]
        self.sr.dynamic_energy_threshold = False
        
        # You can get the list of available devices: sr.Microphone.list_microphone_names()
    # You can set the fault microphone like this: self. mic = sr.Microphone(device_index=3)
    # where the device_index is the position in the list from the first command.

    #prilagodi mikrofon glede na hrup
    def adjustMicrophone(self):
        with self.mic as source:
            print('Adjusting mic for ambient noise...')
            self.sr.adjust_for_ambient_noise(source)
        self.sr.dynamic_energy_threshold = False

    #izpise prompt message in prepozna odgovor preko mikrofona
    def promptAndListen(self, prompt_message):
        with self.mic as source:           
            print(prompt_message)
            audio = self.sr.listen(source)
            #audio = self.sr.listen(source, timeout = 4)
           
        print('Processing...')
        recognized_text = ''
        try:
            recognized_text = self.sr.recognize_google(audio)
        except sr.RequestError as e:
            print('API is probably unavailable', e)
            return -1
        except sr.UnknownValueError:
            print('Did not manage to recognize anything.')
            return -1

        print("Recognized: ", recognized_text)
            
        return recognized_text
        
    # vpraša uporabnika dano vprašanje in čaka na odgovor, če odgovor vsebuje besedo iz seznama legalnih odgovorov vrne odgovor, čene vpraša ponovno
    # če ptevilo neuspelih poskusov preseže max_tries prosi za vnos preko konzole namesto prepoznave govora
    def askUser(self, question, legal_answers, max_tries = 3):
        answer = ""
        i = 0
        while(True):
            i+=1
            if i <= max_tries:
                answer = self.promptAndListen(question)
                if answer == -1:
                    print("Sorry, please try again")
                    continue
            else:
                answer = input("Please provide an answear manually: ")


            if legal_answers == "positive integer":
                #print("expecting uint!")
                #if answer.isdigit:
                if answer.isnumeric():
                    return answer
                else:
                    print("Please provide a positive integer number")

            #elif any (element in answer for element in legal_answers):
            else:
                for element in legal_answers:
                    if element in answer:
                        print("Detected match: ", element)
                        return answer

            print("Sorry, please try again")


    #glavna funkcija 
    def dialog(self):
        answers = {}

        self.adjustMicrophone()         

        already_vaccinated_answer = self.askUser("Have you been vaccinated?", self.affirmative_answers + self.negative_answers)
        if any (element in already_vaccinated_answer for element in self.affirmative_answers):
            answers["already vaccinated"] = True
        else:
            answers["already vaccinated"] = False


        doctor_answer = self.askUser("Who is your doctor?", self.doctors)
        for doc in self.doctors:
            if doc in doctor_answer:
                answers["doctor"] = doc
                break
        
        excercise_answer = self.askUser("How many hours per week do you exercise?", "positive integer")
        answers["hours of exercise"] = excercise_answer

        wants_vaccine_answer = self.askUser("Do you want to be vaccinated?", self.affirmative_answers + self.negative_answers)
        if any (element in wants_vaccine_answer for element in self.affirmative_answers):
            answers["wants vaccine"] = True
        else:
            answers["wants vaccine"] = False
        

        return answers

        """
        format vrnjenega odgovora:
        answers{
            "already vaccinated": True/False,
            "doctor": barva zdravnika iz self.doctors[],
            "hours of exercise": number,
            "wants vaccine": True/False
        }

        """
   


if __name__ == '__main__':
    
    st = SpeechTranscriber()
    answers = st.dialog()

    print(answers)
    """
    for i in range(3):
        
        text = st.recognize_speech()
        print('I recognized this sentence:', text)
        time.sleep(4)
    
    
    while not rospy.is_shutdown():
        text = st.recognize_speech()
        print('I recognized this sentence:', text)
        time.sleep(4)
"""

