n=int(input())
x,y=map(int,input().split())
s=x+y
for i in range(1,n):
    x,y=map(int,input().split())
    if (x+y)>s:
        s=x+y
print(s)
