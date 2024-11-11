S = input()
T = []
for i in range(len(S)-1):
    if S[i] != S[i+1]:
        T.append(max(i+1,len(S)-i-1))
if T != []:
    print(min(T))
else:
    len(S)