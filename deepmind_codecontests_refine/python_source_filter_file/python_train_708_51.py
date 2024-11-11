a, b = map(int, input().split())

s = input()
n = s[:a]+s[a+1:]

print("Yes" if s[a]="-" and n.isdigit() else "No")