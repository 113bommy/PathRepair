#n = int(input())
n, m, k = map(int, input().split())
#s = input()
c = list(map(int, input().split()))
l = 0
x = 0
for i in range(n):
    if c[i] <= k:
        x += 1
        if x >= m:
            l += 1
    else:
        x = 0
print(l)