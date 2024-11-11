n = int(input())
for _ in range(n):
    a,b = map(int,input().split())
    print(max(min(a,b)*2,max(a,b))**2)