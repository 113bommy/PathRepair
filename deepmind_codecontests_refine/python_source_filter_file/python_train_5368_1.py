import queue, math
from itertools import repeat

def binarySearch(arr, l, r, x):
    if r >= l: 
        mid = l + (r - l) // 2
        if arr[mid] == x: 
            return mid 
        elif arr[mid] > x: 
            return binarySearch(arr, l, mid-1, x) 
        else: 
            return binarySearch(arr, mid + 1, r, x) 
    else: 
        return -1

def mergeSort(arr): 
    if len(arr) >1: 
        mid = len(arr)//2 #Finding the mid of the array 
        L = arr[:mid] # Dividing the array elements  
        R = arr[mid:] # into 2 halves 
        mergeSort(L) # Sorting the first half 
        mergeSort(R) # Sorting the second half 
        i = j = k = 0
        while i < len(L) and j < len(R): 
            if L[i] < R[j]: 
                arr[k] = L[i] 
                i+=1
            else: 
                arr[k] = R[j] 
                j+=1
            k+=1
        while i < len(L):
            arr[k] = L[i] 
            i+=1
            k+=1
        while j < len(R): 
            arr[k] = R[j] 
            j+=1
            k+=1

def main():
    n, m, k = input().split()
    if(n == k or k == '0'): return -1
    G = [[] for i in repeat(None, int(n) + 1)]
    for i in range(int(m)):
        line = list(map(int, input().split()))
        G[line[0]].append((line[1], line[2]))
        G[line[1]].append((line[0], line[2]))
    K = list(map(int, input().split()))
    mergeSort(K)
    ans = math.inf
    for i in K:
        for lst in G[i]:
            if(ans > lst[1] and binarySearch(K, 0, len(K) - 1, lst[0])):ans = lst[1]
    return (ans if ans != math.inf else -1)

print(main())
