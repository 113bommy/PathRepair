N = int(input())
a = [int(e) for e in input().split()]

mul4 = len([e for e in a if e % 4 == 0])
mul2 = len([e for e in a if e % 2 == 0])

if mul4 >= N // 2 or mul2 == N or mul2 - mul4 >= N - (mul4 * 2 + 1):
    print('Yes')
else:
    print('No')