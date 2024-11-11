a,b = map(int, input().split())
if abs(a-b) <= 1 and not (a == 0 and b == 0):
    print("YES")
else:
    print("NO")