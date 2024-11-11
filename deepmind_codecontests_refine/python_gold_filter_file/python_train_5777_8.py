N = int(input())
if N == 1:
    print(1)
    print(1)
elif N == 2:
    print(1)
    print(1)
elif N == 3:
    print(2)
    print('1 3')
elif N == 4:
    print(4)
    print('2 4 1 3')

else:
    print(N)
    for i in range(1, N + 1, 2):
        print(i, end=' ')
    for i in range(2, N + 1, 2):
        print(i, end=' ')
        