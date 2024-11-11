n, m = input().split()
n, m = int(n), int(m)
a = [int(i) for i in input().split()]
start = 1
res = 0
for i in a:
    if start <= i:
        res += (i - start)
    else:
        res += (n-start+1 + i-1)
    start = i
print(res)
