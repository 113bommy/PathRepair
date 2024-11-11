a, b = map(int,input().split())
s = input()
print("Yes" if s[:a].isdecimal() and s[a] == "-" and s[a+1:].isdecimal() else "No")