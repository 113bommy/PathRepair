t = int(input())
for _ in range(t):
    n,x = map(int,input().split())
    if n<= 2:
        print(1)
    else:
        n-=2
        print(n//x + 1)