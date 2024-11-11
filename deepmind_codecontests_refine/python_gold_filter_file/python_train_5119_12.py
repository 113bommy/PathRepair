def charu(m):
    global l1
    j = 0
    le = len(l1)
    while (l1[j] < m):
        j += 1
        if (j == le):
            break
    l1 = l1[:j] + [m] +l1[j:]

a, b = list(map(int, input().split()))
l = list(map(int, input().split()))
l1 = [l[0]]
l2 = [0]
su = 0
for i in range(1, a):
    k = 0
    su += l[i-1]
    su1 = su
    while (b - l[i] < su1):
        su1 -= l1[-k-1]
        k += 1
    l2.append(k)
    charu(l[i])
print(*l2)