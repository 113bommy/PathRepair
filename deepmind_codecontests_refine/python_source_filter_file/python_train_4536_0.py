n = int(input())

s = input()
l = s.split()

a = []
la = len(l)

for i in range(la):
    a.append(int(l[i]))

for i in range(la - 1):

    if a[i] < 0:
        print('NO')
        quit()

    if a[i] & 1 == 1:
        a[i + 1] = -1

if a[la - 1] < 0 or a[la - 1] & 1 == 1:
    print('NO')
    quit()

print('YES')
