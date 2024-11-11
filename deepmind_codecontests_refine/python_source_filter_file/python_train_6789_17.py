t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    c=len(str(b))
    print(a*(c-1))
