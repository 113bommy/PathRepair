t = int(input())
while t > 0:
    n = int(input())
    arr1 = sorted(list(map(int, input().split()))[:n])
    arr2 = sorted(list(map(int, input().split()))[:n])

    print(' '.join(map(str, arr1)))
    print(' '.join(map(str, arr1)))


    t = t - 1
