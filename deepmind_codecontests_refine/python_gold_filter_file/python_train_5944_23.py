n = input()
a = list(map(int, input().split()))

for i in a:
    if i % 2 == 0:
        print(i - 1, end=' ')
    else:
        print(i, end=' ')
