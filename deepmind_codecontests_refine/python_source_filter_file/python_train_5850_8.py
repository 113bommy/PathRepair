n=int(input())
for i in range(n):
    a,b,c=map(int,input().split())
    x=min(a,b)
    s=a-x+b-x+c
    if s>=x:
        print(x)
    else:
        print(x-((x-s)//2))