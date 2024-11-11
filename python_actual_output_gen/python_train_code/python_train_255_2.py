a, b = map(int, input().split())
s = input()
print("Yes" if s.count("-") == 1 and s[a] == "-" and s.count() == a+b+1 else "No")