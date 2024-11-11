n = int(input())
num = list(map(int, input().split()))
ua = list()
ub = list()

def swap(i, j):
    t = num[i]
    num[i] = num[j]
    num[j] = t

ans = 0
for i in range(n-1, 0, -1):
    for j in range(i):
        if num[j] > num[j+1]:
            # print(j, j+1)
            ua.append(j)
            ub.append(j+1)
            swap(j, j+1)
            ans += 1
            # print(num)

for i in range(ans):
    print(ua[i] + 1, ub[i] + 1)
