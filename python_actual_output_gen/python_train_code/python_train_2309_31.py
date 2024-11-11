n = int(input())
for _ in range(n):
    x,a,b = map(int, input().split())
    print(x*a if b>a*2 else (x//2)*b + a)
