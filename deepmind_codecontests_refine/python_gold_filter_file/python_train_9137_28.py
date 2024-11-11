from collections import defaultdict
N,P=map(int,input().split())
S=input()

if P==2 or P==5:
    ans=0
    for i in range(N):
        if int(S[i])%P==0:
            ans+=i+1
    print(ans)

else:
    d=defaultdict(int)
    a=0
    for i in range(N):
        a+=int(S[N-i-1])*pow(10,i,P)
        a%=P
        d[a]+=1
    ans=d[0]
    for v in d.values():
        ans+=v*(v-1)//2
    print(ans)
    
