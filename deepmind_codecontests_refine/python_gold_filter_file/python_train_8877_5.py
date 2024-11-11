tc  = int(input())
for _ in range(tc):
    a,b,c,d = map(int,input().split())
    print(max(a+b,c+d))