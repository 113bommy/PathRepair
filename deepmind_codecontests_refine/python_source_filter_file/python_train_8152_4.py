n = int(input())
for _ in range(n):
    input()
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    f = list(map(int, input().split()))

    if (a[0] == b[0]):
        d = abs(a[1]-b[1])
        if (f[0] == a[0]):
            if (abs(a[1]-f[1])+abs(b[1]-f[1]) == abs(a[1]-b[1])):
                d += 2
    elif (a[1] == b[1]):
            d = abs(a[0]-b[0])
            if (f[1] == a[1]):
                if (abs(a[0]-f[0])+abs(b[0]-f[0]) == abs(a[0]-b[0])):
                    d += 2
    else:
        d = abs(a[0]-b[0]) + abs(a[1]-b[1])

print(d)

'''
1
1 1
3 3
2 2
'''