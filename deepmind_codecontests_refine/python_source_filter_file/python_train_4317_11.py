import sys
input = sys.stdin.readline


def main():
    int(input())
    heaps = list(map(int, input().split()))
    sum = 0
    i = 0
    while i < len(heaps):
        heaps[i] = sum + heaps[i]
        sum = heaps[i]
        i += 1
    int(input())
    es = list(map(int, input().split()))
    for e in es:
        print(binarySearch(heaps, e) + 1)

def binarySearch(arr, n):
    first = 0
    last = len(arr) - 1
    while first <= last:
        mid = (first + last) // 2
        if (mid - 1) < 0:
            return mid
        if (n > arr[mid - 1]) and (n <= arr[mid]):
            return mid
        if arr[mid] > n:
            last = mid - 1
        else:
            first = mid + 1

main()