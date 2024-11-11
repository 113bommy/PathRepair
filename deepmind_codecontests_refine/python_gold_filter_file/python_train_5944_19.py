n = input()
ar = list(map(int, input().split()))
for i in ar:
    if i % 2 == 0:
        print(i - 1, end=' ')
    else:
        print(i, end=' ')
