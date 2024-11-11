string = input()
s = "ywrtpsdfghjklzxcvbnm";
posl = 0
word_answer = ""
otvet = 0
for i in range(len(string)):
    if s.find(string[i]) != -1:
        otvet+=1
    else:
        otvet = 0
    if (otvet >= 3):
        if string[i] != string[i-1] or string[i] != string[i-2] or string[i-1] != string[i-2]:
            word_answer=word_answer+string[posl:i]+" "
            posl = i
            otvet = 0
            if s.find(string[i]) != -1:
                otvet+=1
word_answer = word_answer+string[posl:]
print(word_answer)