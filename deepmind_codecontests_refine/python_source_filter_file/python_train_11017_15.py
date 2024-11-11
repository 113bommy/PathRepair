A = int(input())
a = list(map(int, input().split()))
mx = max(a)
mn = min(a)

if mn >= 0:
    print(A-1)
    for i in range(1, A+1):
        print(i, i+1)
elif mx <= 0:
    print(A-1)
    for i in range(A, 1, -1):
        print(i, i-1)
else:
    print(A*2-1)
    if mx >= abs(mn):
        index = a.index(mx) + 1
        for i in range(1, A+1):
            print(index, i)
        for i in range(1, A):
            print(i, i+1)
    else:
        index = a.index(mn) + 1
        for i in range(1, A+1):
            print(index, i)
        for i in range(A, 1, -1):
            print(i, i-1)
