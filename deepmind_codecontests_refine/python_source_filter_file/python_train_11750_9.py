S=input()
ans=0
for i in range(2**(len(S)-1)):
    tmp=S[0]
    for j in range(len(S)-1):
        if ((i >> j) & 1) == 1:
            x+="+"
        x+=S[j+1]
    ans+=eval(x)
print(ans)