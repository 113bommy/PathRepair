# Problem code: 1228A

l, p = input().split()
l, p = int(l), int(p)
found = False
for x in range(l+1, p):
    if len(str(x)) == len(set(str(x))):
        print(x)
        found = True
        break
if not found:
    print(-1)