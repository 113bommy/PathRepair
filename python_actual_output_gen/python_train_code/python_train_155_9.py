n=int(input());b=[]
for i in range(n):
    x=int(input())
    y=list(map(int,input().split()))
    z=set(y)
    b.append(len(z))
for i in b:
    print(b)
