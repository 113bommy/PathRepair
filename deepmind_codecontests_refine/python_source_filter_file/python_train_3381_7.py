x, y, n = map(int, input().split())

if(x%2 + y%2 == n%2 and abs(y) + abs(x) <= n):
    print("Yes")
else:
    print("No")
