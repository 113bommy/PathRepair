t = int(input())
for i in range(t):
    a,b = map(int,input().split())
    print(max(min(a,b)*2,max(a,b))**2)