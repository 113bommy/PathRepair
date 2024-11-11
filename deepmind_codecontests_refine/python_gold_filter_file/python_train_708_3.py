a,b = map(int,input().split())
s = input()
print("Yes" if s.count("-") == 1 and s[a] == "-" and len(s) == a+b+1 else "No")