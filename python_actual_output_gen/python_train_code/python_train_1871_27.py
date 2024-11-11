n = int(input())
s = input()
print("Yes" if n % 2 == 0 and s[:n/2] == s[n/2:] else "No")
