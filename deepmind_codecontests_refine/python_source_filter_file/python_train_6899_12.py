import sys, bisect

arr = list(sys.stdin.readline().rstrip())
n = len(arr)
if arr == arr[::-1]:
    print(0)
else:
    print(4)
    print('R %d' % (n - 1))
    arr += [arr[-2]]
    n = len(arr)
    print('L %d' % 2)
    arr = [arr[1]] + arr
    n = len(arr)
    print('R %d' % (n - 1))
    arr = arr + arr[1:n - 1][::-1]
    n = len(arr)
    print('R %d' % (n - 1))
    arr += [arr[-2]]