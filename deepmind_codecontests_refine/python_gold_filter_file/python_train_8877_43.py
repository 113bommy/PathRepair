n = int(input())
for _ in range(n):
    a,b,c,d = map(int,input().split())
    print(max(a+b,c+d))
