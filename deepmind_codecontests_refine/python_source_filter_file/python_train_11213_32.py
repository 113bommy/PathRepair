N = int(input())
if N == 1:
    print(-1)
elif N == 2:
    a,b = map(int, input().split())
    if a == b:
        print(-1)
    else:
        print('1\n1')
else:
    arr = sorted(list(map(int, input().split())))
    if arr[0] == sum(arr[1:]):
        print('2\n1 2')
    else:
        print('1\n1')


