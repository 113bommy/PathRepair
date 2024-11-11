t =int(input())
for q in range(t):
    abcm = [int(x) for x in input().split()]
    a = int(abcm[0])
    b = int(abcm[1])
    c = int(abcm[2])
    m = int(abcm[3])
    arr = [a,b,c]
    arr.sort()
    if m <= a+b+c - 3 and m>= arr[2] - 2*arr[0] -(arr[1]-arr[0]) - 1  :  #m >= arr[2] - arr[1] -1:
        print('YES')
    else:
        print('NO')

