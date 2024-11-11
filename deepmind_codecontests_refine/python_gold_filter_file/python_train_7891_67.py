S = input()
li =[]
for i in range(len(S)-2):
    li.append(abs(int(S[i:i+3])-753))
print(min(li))