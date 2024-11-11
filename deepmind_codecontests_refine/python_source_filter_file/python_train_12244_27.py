n, k = map(int, input().split())
s = input()
d = {}
count = 0
for i in s:
    d[i] = d.get(i,0) + 1
print(d, len(d))
for i in d:
    yes = False
    if d[i] <= k:
        yes = True
    else:
        print("NO")
        break
if yes:
    print('YES')
