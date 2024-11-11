S=(input().split(" "))
p=0
for i in range(len(S)-1):
    if i<len(S):
        if S[i]==S[i+1]:
            p=p+1
        else:
            continue
    else:
        break
print(p)