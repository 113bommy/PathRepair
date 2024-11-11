k = int(input())
s = input()

if len(s) > k:
    s = s[0:k] + "..."

print(s)