w,h=map(int,input().split())
p=998244353
x=(w*h)%p
y=(x*x)%p
print(y)