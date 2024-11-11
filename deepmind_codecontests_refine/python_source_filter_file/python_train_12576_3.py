N=int(input())
b,ba,a=0,0,0
ans=0
for i in range(N):
    s=input()
    for i in range(len(s)-1):
        if s[i:i+2]=='AB':
            ans+=1
    if s[0]=='B' and s[-1]=='A':
        ba+=1
    elif s[-1]=='A':
        a+=1
    elif s[0]=='B':
        b+=1
if b==a==0:
    print(ans+min(ba-1,0))
else:
    print(ans+ba+min(a,b))