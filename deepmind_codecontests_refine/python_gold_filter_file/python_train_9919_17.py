t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    if(n <3):
        print(1)
    else:
        n-=3
        print(n//x + 2)
