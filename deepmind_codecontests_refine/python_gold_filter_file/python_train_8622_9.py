f = [False for i in range(100001)]
c = [0 for i in range(100001)]

for i in range(2, 100001):
    if not f[i]:
        for j in range(2*i, 100001, i):
            f[j] = True
for i in range(3, 100001, 2):
    if not f[i] and not f[int((i+1)/2)]:
        c[i] += 1
for i in range(3, 100001):
    c[i] += c[i-1]
    
n = int(input())
while n:
    l, r = list(map(int, input().split()))
    print (c[r]-c[l-1])
    n -= 1
