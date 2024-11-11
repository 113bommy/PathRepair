n = int(input())
s = input()
l = set(s)
if len(l) > 26:
    print(-1)
else:
    print(n - len(l))