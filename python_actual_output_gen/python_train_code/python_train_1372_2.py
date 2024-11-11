# Nhập liệu
n, k = map(int, input().split())
A = list(map(int, input().split()))
A.append(0)
RES = {}
count = 0
li = 0
for i in range(1, n+1):
    if A[i] not in RES:
        RES[A[i]] = 1
    else:
        RES[A[i]] += 1
    if RES[A[i]] == 1:
        count += 1
    while count == k:
        li += 1
        if A[li] not in RES:
            RES[A[li]] = 0
        RES[A[li]] -= 1
        if RES[A[li]] == 0:
            print(li, i)
            exit()
print(-1, -1)