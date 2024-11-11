a,b = map(int, input().split())
s = input()
print("Yes" if s[0:a].isdecimal() and s[a] == "-" and s[:b-1:-1].isdecimal() else "No")