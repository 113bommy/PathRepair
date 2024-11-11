n, a, b, c, d = map(int, input().split())
s = input()
if ("##" in s[min(a, b): max(c, d)]) or (d < c and "..." not in s[b-1: d+1]):
    print("No")
else:
    print("Yes")