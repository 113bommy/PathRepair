# c = int(input())
# for i in range(c):
#     n = int(input())
#     a = list(map(int, input().split()))
#     point = 0
#     pos = 0
#     while pos<n:
#         FriendTurn()
#         MyTurn()
#     print(point)

n = int(input())
a = list(map(int, input().split()))
if n==1:
    print(1, 1)
    print(-a[0])
    print(1, 1)
    print(0)
    print(1, 1)
    print(0)
else:
    print(1, n-1)
    for i in range(0, n-1):
        print(a[i]*(n-1), end=' ')
    print('\n', 1, n)
    for i in a:
        print(i*(-n), end=' ')
    print('\n', n, n)
    print(a[n-1]*(n-1))



