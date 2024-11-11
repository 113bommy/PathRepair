def mergeSort(A,left,right):
    if left + 1 < right:
        mid = (left+right)//2
        mergeSort(A,left,mid)
        mergeSort(A,mid,right)
        merge(A,left,mid,right)

def merge(A,left,mid,right):
    global count
    L = A[left:mid]
    R = A[mid:right]
    L.append(1000000000)
    R.append(1000000000)

    i = 0
    j = 0
    for k in range(left,right):
        if L[i] < R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            count += len(L) - i - 1
            j += 1

n = int(input())
nums = list(map(int,input().split(" ")))
count = 0

mergeSort(nums,0,n)
print(count)

