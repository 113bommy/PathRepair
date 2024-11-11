k,a,b=map(int, input().split())
t=1
if t<a:
    k-=(a-t)
    t=a
if b-a>2:
    t+=(k//2)*(b-a)
    k=k//2
t+=k
print(t)