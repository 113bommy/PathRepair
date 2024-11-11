s=input()
l=len(s)
amari=[0]*2019
amari[0]=1

d=0
digi=1

for c in s[::-1]:
    d=(int(c)*digi + d)%2019
    amari[d]+=1
    digi=(digi*10)%2019

ans=0
for i in amari:
    ans+=i*(i-1)//2
print(ans)