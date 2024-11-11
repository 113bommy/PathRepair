x=0
n,k=map(int,input().split())
for i in map(int,input().split()):
    n-=1
    x+=i*k**n
y=0
n,k=map(int,input().split())
for i in map(int,input().split()):
    n-=1
    y+=i*k**n
print('=' if x==y else '<' if x < y else '>')