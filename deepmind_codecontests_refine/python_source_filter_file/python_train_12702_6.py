n = int(input())
a = list(map(int, input().split()))
input()
m = list(map(int, input().split()))

n2 = n**2
aa = [0 for _ in range(n2)]
for i in range(n):
    t = 2**i
    for j in range(n2):
        if (j//t)%2:
            aa[j] += a[i]
aa = set(aa)

for k in m:
    if k in aa:
        print('yes')
    else:
        print('no')