a, b = map(int, input().split())
s = input()
print("Yes" if s[a] == "-" and s[:a].isdecimal() and s[b:].isdecimal() else "No")
