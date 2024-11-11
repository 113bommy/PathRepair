n = int(input())
for i in range(n):
    a,b,c,d = map(int,input().split())
    print(max(a+b,c+d))