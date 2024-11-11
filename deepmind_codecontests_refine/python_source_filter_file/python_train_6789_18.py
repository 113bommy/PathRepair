t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    l=len(str(b))
    print(a*(l-1))