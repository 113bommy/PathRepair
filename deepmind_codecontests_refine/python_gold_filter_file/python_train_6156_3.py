n=int(input())
s=str(input())

f=s[0]
l=s[-1]
fc=lc=0


for i in range(0,n):
    if s[i]==f:
        fc+=1
    else:
        break

for i in range(0,n):
    if s[n-i-1]==l:
        lc+=1
    else:
        break

if l!=f:
    print(int(fc+lc+1)%998244353)
else:
    ans=fc+lc+1
    ans+=fc*lc
    print(int(ans)%998244353)
