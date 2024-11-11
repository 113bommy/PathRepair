n = int(input())
raiting = list(map(int, input().split()))
raiting.sort()
if raiting[n - 1] > raiting[n - 2]:
    print('YES')
else:
    print('NO')
