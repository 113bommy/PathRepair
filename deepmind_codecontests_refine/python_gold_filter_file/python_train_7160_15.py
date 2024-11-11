s = input()
d = len(s)//2
print("Yes" if s[:d] == s[d+1:] else "No")