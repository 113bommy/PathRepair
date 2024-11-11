t = int(input())

for i in range(t):
    a, b, n, m = map(int, input().split())
    if m < min(a, b) and a+b >= n+m:
        print("Yes")
    else:
        print("No")