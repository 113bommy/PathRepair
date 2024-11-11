import sys
n=int(input())
s=input()
frac=[0]*(n+1)
for i in range(1,n+1):
    k=i
    frac[i]=frac[i-1]
    while k%2==0:
        k//=2
        frac[i]+=1

ans=0
for i in range(n):
    if int(s[i])==2 and frac[n-1]-frac[i]-frac[n-1-i]==0:
        ans^=1

if ans==1: print(1)
elif "1" in s: print(0)
else:
    ans=0
    for i in range(n):
        if int(s[i])==3 and frac[n-1]-frac[i]-frac[n-1-i]==0:
            ans^=1
    print(ans*2)
