a = input()
b = input()

c = 0
res = list(a)
for i in range(len(a)):
    if a[i] != b[i]:
        if c % 2 == 1:
            res += b[i]
        c += 1

if c % 2 == 1:
    print("impossible")
else:
    print(''.join(res))