import sys
#sys.stdin = open('in', 'r')
#n = int(input())
n,m = map(int, input().split())
a = [1]*n
for i in range(n):
    a[i] = -(n - i)
Ok = True
srt = []
for ti in range(m):
    t,l,r = map(int, input().split())
    l -= 1
    r -= 1
    if t == 1:
        v = abs(a[l])
        for j in range(l, r):
            a[j] = v
        if a[r] > 0:
            over = a[r]
            l = r + 1
            while l < n and a[l] == over:
                a[l] = v
                l += 1
        a[r] = v
    else:
        srt.append((l,r))

for i in range(n):
    if a[i] < 0:
        a[i] = -a[i]

for i in range(len(srt)):
    l,r = srt[i]
    cnt = 0
    for j in range(l, r):
        if a[j] > a[j+1]:
            cnt += 1
            break
    if cnt == 0:
        Ok = False

if Ok:
    print('YES')
    print(' '.join(map(str, a)))
else:
    print('NO')



#sys.stdout.write('YES\n')
#sys.stdout.write(f'{res}\n')
#sys.stdout.write(f'{y1} {x1} {y2} {x2}\n')
