t = int(input())
for _ in range(t):
    N, M = map(int, input().split())
    if N%M == 0:
        print("YES")
    else:
        print("NO")
