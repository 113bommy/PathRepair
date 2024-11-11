N, M = input().strip().split()
n, k = [int(N), int(M)]
a = list(map(int, input().strip().split()))
le = 0
ri = 10000000000
while ri - le > 1:
    mid = (le + ri)// 2
    num = 0
    for i in a:
        num += (i-1)// mid
    if num <= k:
        ri = mid
    else:
        le = mid
print(ri)
