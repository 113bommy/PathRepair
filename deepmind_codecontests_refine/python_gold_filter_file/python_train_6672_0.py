n = int(input())
a = []
for i in range(n):
    a.append([int(x) for x in input().split()])

def shet(a):
    s = max(a[0][0], a[0][1])
    for i in range(1, n):
        k = 0
        s1 = max(a[i][0], a[i][1])
        if s1 <= s:
            s = s1
            k += 1
        elif min(a[i][0], a[i][1]) <= s:
            s = min(a[i][0], a[i][1])
            k += 1
        if k == 0:
            return 'NO'
    return 'YES'

print(shet(a))
