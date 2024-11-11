l = map(int, input().split())
print("Yes" if l.sort() == [5, 5, 7] else "No")