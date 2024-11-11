def merge(a, left, mid, right):
    global count
    n1 = mid - left
    n2 = right - mid
    L = a[left:left + n1] + SENTINEL
    R = a[mid:mid + n2] + SENTINEL
    i = j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
    count += right - left

def merge_sort(a, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(a, left, mid)
        merge_sort(a, mid, right)
        merge(a, left, mid, right)

SENTINEL = 1000000001
n = int(input())
a = list(map(int, input().strip().split()))
count = 0
merge_sort(a, 0, len(a))
print(' '.join(map(str, a)))
print(count)