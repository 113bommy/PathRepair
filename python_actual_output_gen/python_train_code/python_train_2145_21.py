S=input()
T=input()
ans=0
for i in range(len(S)-len(T)):
    k=0
    for j in range(len(T)):
        if S[i+j]==T[j]:
            k+=1
    ans=max(k,ans)
print(len(T)-ans)
