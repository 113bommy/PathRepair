n = int(input())
for i in range(1, 1000):
    if i*(i+1)//2>n:
        print('No')
        exit(0)
    if i*(i+1)//2==n:
        break
q = list(range(n, 0, -1))
ans = []
for j in range(i+1):
    tmp = []
    for k in ans:
        tmp.append(k[j-1])
    for _ in range(i-j):
        tmp.append(q.pop())
    ans.append(tmp)
print('Yes')
print(i+1)
for j in ans:
    tmp = [i]+j
    print(*tmp)