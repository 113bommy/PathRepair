t= int(input())
for _ in range(t):
    n,m = map(int, input().split())

    if n/3 == 2:
        print("YES")
    else:
        print("NO")
