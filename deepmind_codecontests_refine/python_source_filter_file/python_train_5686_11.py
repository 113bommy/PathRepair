import sys

n = int(input())

a=[]

tv1 = 0
tv2 = 0
for _ in range(n):
    a += [tuple(map(int,sys.stdin.readline().split()))]

a.sort()

for i in range(n):
    s,e = a[i]

    if s > tv1:
        tv1=e
    elif s > tv2:
        tv2=e
    else:
        break
else:
    print('YES')
    exit()
print('NO')
