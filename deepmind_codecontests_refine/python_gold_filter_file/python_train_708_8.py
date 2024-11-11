n, m = map(int,input().split())
s = input()
print("Yes" if s[n] == "-" and s[:n].isdecimal() and s[n+1:].isdecimal() else 'No')