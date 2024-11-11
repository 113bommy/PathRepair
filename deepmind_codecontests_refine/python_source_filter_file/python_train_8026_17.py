n=int(input())
s=0
for i in range(n):
    x,y=map(int,input().split())
    s1=x+y
    if(s1>s):
        s=s1
print(s1)