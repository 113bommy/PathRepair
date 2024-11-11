x, y = map(int, input().split())
a = list(map(int, input().split()))
print("yes" if sum(a) >= x else "no")