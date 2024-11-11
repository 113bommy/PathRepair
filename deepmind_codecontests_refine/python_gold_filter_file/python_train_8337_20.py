n, k = map(int, input().split())
s = input()

i = 1
while s[i:] != s[:-i]: i+=1
print(s[:i] * k + s[i:])
