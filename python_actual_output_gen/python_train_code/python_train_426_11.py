# print("Enter the string")
st = input()
vowels = ['A','E','I','O','U','Y']

vowelpos = [0]
for i in range(len(st)):
    if st[i] in vowels:
        vowelpos.append(i)
vowelpos.append(len(st))

answer = 0
for i in range(1, len(vowelpos)):
    if vowelpos[i] - vowelpos[i-1] > answer:
        answer = vowelpos[i] - vowelpos[i-1]

print(answer)


    


