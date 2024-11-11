s = input()
a = [0, 0]
for i in s:
    if i == 'o':
        a[0] += 1
    else:
        a[1] += 1
if a[0] % 2 == 0 and a[0] >= 2:
    if a[1] % 2 == 0 and (a[1] >= a[0] or a[1] == 0):
        print("YES")
    else:
        print("NO")
elif a[0] % 2 == 1 and a[0] >= 2:
    if a[1] % a[0] == 0 and (a[1] >= a[0] or a[1] == 0):
        print("YES")
    else:
        print("NO")
else:
    print("YES" if a[0] < 2 else "NO")