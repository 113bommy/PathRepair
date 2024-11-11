n, m=map(int, input().split())
i=0
t=n
while n-2*i>0:
    if (n-i)%m==0 and (n-i)<t:
        t=n-i
    i+=1
if t%m==0:
    print(t)
else:
    print(-1)