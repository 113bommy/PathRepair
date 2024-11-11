n=int(input())
f=True
for i in range(2,int(n**0.5)+1):
    if n%i==0:
        m=i
        f=False
        break
if f: m=n
n-=m
c=1+n//2
print(c)
