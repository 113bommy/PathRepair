a=int(input())
b=sorted(map(int,input().split()))
s=0
c=0
while s<sum(b):
    s=s+b.pop()
    c=c+1
print(c)
