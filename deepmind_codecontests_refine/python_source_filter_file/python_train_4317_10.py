def binarySearchCount(arr, n, key):
    left = 0
    right = n - 1

    count = 0

    while (left <= right):
        mid = int((right + left) / 2)

        # Check if middle element is
        # less than or equal to key
        if (arr[mid] <= key):
            count = mid+1
            left = mid + 1

        # If key is smaller, ignore right half
        else:
            right = mid - 1
    return count
def main():
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    q = list(map(int, input().split()))
    d = []
    c = 0
    for i in range(n):
        d.append(c + 1)
        c = c + a[i]
        d.append(c)
    print(d)
    for i in range(m):
        if q[i] == d[len(d) - 1]:
            print(len(d) // 2)
        else:
            print((binarySearchCount(d,len(d),q[i])+1)//2)
if __name__ == '__main__':
    main()