N = int(input())

k = 0
while N != k*(k-1)//2:
    k += 1
    if k == 1000:
        break

if k == 1000:
    print("No")
else:
    ans = [[] for _ in range(k)]
    cnt = 0
    for i in range(k):
        for j in range(i+1,k):
            ans[i].append(cnt+1)
            ans[j].append(cnt+1)
            cnt += 1

    print("Yes")
    print(k)
    for a in ans:
        print(k-1, *a)