t = int(input())
for i in range(t):
    n = int(input())
    c = 0
    array = list(map(int,input().split()))
    for i in range(n):
        array[i] = array[i] % 2
    zeros = array.count(0)
    ones = array.count(1)
    if zeros == ones or zeros - 1 == ones:
        for i in range(0,n,2):
            if array[i] == 1:
                c += 1
        print(c)
    else:
        print(-1)