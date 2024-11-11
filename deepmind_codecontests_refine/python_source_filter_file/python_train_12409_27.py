l, r = map(int, input().split())
for i in range(l, r):
    s = str(i)
    if len(s) == len(set(s)):
        print(i)
        exit()
print(-1)
