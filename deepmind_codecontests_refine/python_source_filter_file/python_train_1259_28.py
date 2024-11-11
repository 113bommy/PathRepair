import math

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def getCharPos(char):
    for i in range(0, len(alphabet)):
        if char == alphabet[i]:
            return i

def getPrev(char):
    position = getCharPos(char)
    if position == 0: return 'a'
    else: return alphabet[position - 1]

def getNext(char):
    position = getCharPos(char)
    if position == 25: return 'z'
    else: return alphabet[position + 1]

inp = list(map(int,input().split()))

t = inp[0]
answers = []
strings = []

def isPalindrome(str):
    for i in range(0, len(str) // 2):
        prevPrev = getPrev(str[i]) == getPrev(str[len(str) - i - 1])
        prevNext = getPrev(str[i]) == getNext(str[len(str) - i - 1])
        nextNext = getNext(str[i]) == getNext(str[len(str) - i - 1])
        nextPrev = getNext(str[i]) == getPrev(str[len(str) - i - 1])
        if (prevPrev or prevNext or nextNext or nextPrev) == True:
            continue
        else:
            return "NO"


    return "YES"


for i in range(0, t):
    str_len = list(map(int, input().split()))[0]
    string = list(map(str, input().split()))[0]

    answers.append(isPalindrome(string))

for answer in answers:
    print(answer)