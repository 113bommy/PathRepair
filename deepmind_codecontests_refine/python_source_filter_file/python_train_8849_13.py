def merge(A, left, mid, right):
    global cnt
    inf = 500000001
    n1, n2 = mid - left, right - mid
    L, R = A[left:left+n1]+[inf], A[mid:mid+n2]+[inf]
    i = j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        cnt += 1

def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

cnt = 0
n = int(input())
A = list(map(int, input().strip().split()))
mergeSort(A, 0, n)
print(*A)
print(cnt)