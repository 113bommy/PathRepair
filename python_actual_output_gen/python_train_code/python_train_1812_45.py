t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    m=b%a
    if (m):
        print(a-m)
    else:
        print(0)
