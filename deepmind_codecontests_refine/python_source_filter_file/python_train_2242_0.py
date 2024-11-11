n=int(input())
s=input()
l=list(map(int,input().split()))
d=[0]*n
i=0
while(0<=i<n):
    if(d[i]==1):
        break
    d[i]=1
    if(s[i]=='<'):
        i+=l[i]*(-1)
    else:
        i+=l[i]*1
if(i>=0 and i<=n):
    print("INFINITE")
else:
    print("FINITE")
