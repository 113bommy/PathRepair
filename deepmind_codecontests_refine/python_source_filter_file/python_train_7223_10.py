##################
# @ July 5th 2019.
##################

#################################################################
# Getting Sentence Count from Codeforces.
sentenceCount = int(input())
# Dictionary for Display.
display = {
    0:'Rainbow\'s',1:'Freda\'s',2:'OMG>.< I dont\' know !'
}
# Method to Display verdict.
def showVerdict(verdict):
    if verdict[0] ^ verdict[1]:
        print(display[0]) if verdict[0] else print(display[1])
    else: print(display[2])
# Algorithm.
status = [False,False]
for i in range(sentenceCount):
    newSentence = input()
    status[1] = newSentence[-5:-1]+newSentence[-1] == 'lala.'
    status[0] = newSentence[0:5] == 'miao.'
    showVerdict(status)
#################################################################

                          ########################################
                          # Programming-Credits atifcppprogrammer.
                          ########################################
