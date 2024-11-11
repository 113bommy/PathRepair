s = input()
countA = 0
counta = 0
for i in range(len(s)):
    if s[i] >= 'A' and s[i] <= 'Z':
        countA = countA + 1
    elif s[i] >= 'a' and s[i] <= 'z':
       counta = counta + 1
print(countA)
print(counta)
if countA > counta:
    print(s.upper())

elif countA <= counta:
#    s.lower()
    print(s.lower())  