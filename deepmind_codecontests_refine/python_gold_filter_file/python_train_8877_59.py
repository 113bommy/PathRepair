t = int(input())
for j in range(t):
    a,b,c,d = map(int,input().split())
    print(max(a+b,c+d))