n = int(input())
l = list(map(int, input().split()))
a = []
m = int(input())
l2 = list(map(int, input().split()))

for j in range(0, m):
    for i in range(0, n):

        if l2[j] % l[i] == 0:
            a.append(l2[j] / l[i])
print(a)
mx = max(a)
print(a.count(mx))