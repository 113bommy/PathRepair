s = sorted(list(map(int, input().split())))
print("Yes" if s[2]==sum(s[:2]) else "No")