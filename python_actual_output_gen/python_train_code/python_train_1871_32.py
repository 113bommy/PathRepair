n = int(input())
s = input()

if s[:n-1] == s[n-1:]:
    print("Yes")
else:
    print("No")