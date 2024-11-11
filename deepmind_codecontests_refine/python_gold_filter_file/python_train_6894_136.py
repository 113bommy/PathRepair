t = int(input())
for _ in range(t):
    m,n = map(int,input().split())
    if m%n == 0:
        print("YES")
    else:
        print("NO")
