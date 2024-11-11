n = int(input())
S = list(map(int, input().split()))
SENTINEL = 10 ** 10 + 1
count = 0

def merge(S, left, mid, right):
    L = S[left:mid] + [SENTINEL]
    R = S[mid:right] + [SENTINEL]
    i = j = 0
    global count
    for k in range(left, right):
        if (L[i] <= R[j]):
            S[k] = L[i]
            i += 1
        else:
            S[k] = R[j]
            j += 1
    count += right - left

def mergeSort(S, left, right):
    if(left + 1 < right):
        mid = (left + right) // 2
        mergeSort(S, left, mid)
        mergeSort(S, mid, right)
        merge(S, left, mid, right)

mergeSort(S, 0, n)
print(*S)
print(count)