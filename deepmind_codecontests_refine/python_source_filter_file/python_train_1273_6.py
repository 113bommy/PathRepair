n = int(input())
mass = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]
pol = list()
otr = list()

for i in range(n):
    x = mass[i] - arr[i]
    if x > 0:
        pol.append(x)
    else:
        otr.append(x)

otr.sort()
pol.sort()
l1 = 0
l2 = 0
m = len(otr)
n = len(pol)
answer = n * (n - 1) // 2

while l1 < n and l2 < m:
    if pol[l1] > -otr[l2]:
        l2 += 1
    else:
        answer += l2
        l1 += 1

answer += (n - l1) * m

print(answer)