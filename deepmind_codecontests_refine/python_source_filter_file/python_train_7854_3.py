n = int(input())
A, B = list(), list()
check = set()
for i in range(n):
    a, b = map(int,input().split())
    A.append(a);B.append(b)
    check.add(a)
check = sorted(check)
val = dict()
for x in check:
    val[x] = list()
for i in range(n):
    val[A[i]].append(B[i])
main_lst = list()
for x in check:
    val[x].sort()

itr, ans = 0, 0
for x in check:
    if itr == 0:
        prev = max(val[x])
        itr += 1
    else:
        if prev > max(val[x]):
            prev = x
        else:
            prev = max(val[x])
print(prev)