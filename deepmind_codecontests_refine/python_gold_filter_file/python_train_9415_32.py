n,d = input().split()
n=int(n)
d=int(d)
s=0
l=input().split()
for i in range(n):
    l[i]=int(l[i])
    s+=l[i]

if(s+(n-1)*10<=d):
    d=d-(s+(n-1)*10)
    k=2*(n-1)
    while(d>=5):
        d-=5
        k+=1
    print(k)
else:
    print(-1)

