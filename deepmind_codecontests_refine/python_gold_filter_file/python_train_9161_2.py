cnt = 0
def merge(A,left,mid,right):
    global cnt
    n1 = mid - left
    n2 = right - mid

    L = [A[i] for i in range(left, mid)]
    R = [A[i] for i in range(mid, right)]
    L.append(float("inf"))
    R.append(float("inf"))
    i = 0
    j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            cnt += n1 - i
            A[k] = R[j]
            j += 1

def mergeSort(A,left,right):
        if left + 1 < right:
            mid = (left+right) // 2
            mergeSort(A,left,mid)
            mergeSort(A,mid,right)
            merge(A,left,mid,right)

input()
a = list(map(int, input().split()))
mergeSort(a, 0, len(a))
print(cnt)

