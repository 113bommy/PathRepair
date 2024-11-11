n = int(input())
a = sorted(list(map(int, input().split())))
for i in range(1, 3001):
    if i not in a:
        print(i)
        exit(0)
