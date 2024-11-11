a, b = map(int,input().split())
s = input()
print("Yes" if s[a]=="-" and s[:2].isdecimal() and s[a+1:].isdecimal() else "No")