n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    if abs(a-b)%2!=0:
        print(-1)
        break
    if a==b and a==0:
        print(0)
    elif a==b:
        print(1)
    else:
        print(2)