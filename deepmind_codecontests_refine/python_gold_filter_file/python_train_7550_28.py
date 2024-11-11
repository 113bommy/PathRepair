n = int(input())
s = input()
l = set(s)
if n > 26:
    print(-1)
else:
    print(n - len(l))