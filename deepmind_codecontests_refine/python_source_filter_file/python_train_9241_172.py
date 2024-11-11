k = int(input())
s = input()

if k <= len(s):
    s = s[0:k] + "..."

print(s)