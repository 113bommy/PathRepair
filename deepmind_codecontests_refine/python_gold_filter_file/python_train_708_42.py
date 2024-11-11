a, b = map(int, input().split())
s = input()
print("Yes" if s[a] == "-" and s[:a].isdigit() and s[b+1:].isdigit() else "No")
