n = int(input())
a = input()
f = 0
s = 0
for i in range(n - 1):
    if a[i] != a[i+1]:
        if a[i+1] == 'F':
            f += 1
        else:
            s += 1
if f > s:
    print('Yes')
else:
    print('No')