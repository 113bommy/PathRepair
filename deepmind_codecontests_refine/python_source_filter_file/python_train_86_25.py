s = sorted(list(map(int, input().split())))
print("YES" if s[2]==sum(s[:2]) else "NO")