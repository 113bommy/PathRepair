def merge(a, left, mid, right):
    global cnt
    l = a[left:mid] + [10**9 + 1]
    r = a[mid:right] + [10**9 + 1]

    i = 0
    j = 0
    for k in range(left, right):
        cnt += 1
        if l[i] <= r[j]:
            a[k] = l[i]
            i += 1
        else:
            a[k] = r[j]
            j += 1


def mergesort(a, left, right):
    if left+1 < right:
        mid = (left + right)//2
        mergesort(a, left, mid)
        mergesort(a, mid, right)
        merge(a, left, mid, right)
    pass


n = int(input())
S = list(map(int, input().split()))
cnt = 0
mergesort(S, 0, n)
print(*S)
print(cnt)