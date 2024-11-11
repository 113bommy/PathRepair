a, b = map(int, input().split())
s = input()
print("Yes" if s[:a].isdecimal() and s[a:b] == "-" and s[b:].isdecimal() else "No")
