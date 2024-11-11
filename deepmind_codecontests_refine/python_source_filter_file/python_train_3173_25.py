import sys
f = sys.stdin
#f = open('H:\\Portable Python 3.2.5.1\\test_248B1.txt') 

n, k = map(int, f.readline().strip().split())
a = [int(u) for u in f.readline().strip().split()]

min_a = min(a)
max_a = max(a)

if max_a>min_a+k-1:
    print('NO')
else:
    print('YES')
 
    for i in range(n):
        d = ['']*a[i]
        for j in range(a[i]):
            if j<min_a:
                d[j] = '1'
            else:
                d[j] = str(2 + j - min_a)
        print(' '.join(d))
        