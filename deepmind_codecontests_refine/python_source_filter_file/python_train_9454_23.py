N = int(input())
k = 1
n = 0
while n < N:
    n += k
    k += 1
if n!=N:
    print('No')
    exit()
print('Yes')
print(k)
ans = [[] for _ in range(k)]
v = 1
for i in range(k-1):
    for j in range(i+1,k):
        ans[i].append(v)
        ans[j].append(v)
        v += 1
for row in ans:
    print(len(row)+ *row))
