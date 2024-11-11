S=list(input())
K=int(input())
l=[1]
for i in range(len(S)-1):
    if S[i]==S[i+1]:l[-1]+=1;
    else:l.append(1)
if len(l)==1:ans = len(S)*K/2;
else:
    l2=[i/2 for i in l]
    if S[0]==S[-1]:
        ht=(l[0]+l[-1])//2
        ans=l2.pop(0)
        ans+=l2.pop(-1)
        ans+=sum(l2)*K
        ans+=ht*(K-1)
    else:
        ans=sum(l2)*K
print(ans)
    
