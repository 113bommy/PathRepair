N=int(input())
S=input()
ANS=""
for i in range(len(S)):
    ANS+=chr(64+((ord(S[i])+N)-64)%26)
print(ANS)