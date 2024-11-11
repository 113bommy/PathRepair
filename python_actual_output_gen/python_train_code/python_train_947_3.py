n = int(input())
a = [int(i) for i in input().split()]

if n == 1:
    print(a[0])
    exit()

mx, mxi = -10**10, -1
mn, mni = 10**10, -1
for i in range(n):
    if a[i] > mx:
        mx, mxi = a[i], i
    elif a[i] < mn:
        mn, mni = a[i], i

if mn < 0:
    if mx < 0:
        print(-sum(a) + 2 * mx)
    else:
        print(sum([abs(i) for i in a]))
else:
    print(sum(a) - 2 * mn)
