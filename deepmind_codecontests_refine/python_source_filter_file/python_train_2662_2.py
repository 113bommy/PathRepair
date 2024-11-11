n, a, b = map(int, input().split())
s = input()

print(1) if s[a - 1] == s[b - 1] else print(0)
