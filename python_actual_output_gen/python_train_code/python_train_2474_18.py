s = input()
print("Yes" if s == s[::-1] and s[:len(s)//2] == s[:len(s)//2:-1] else "No")