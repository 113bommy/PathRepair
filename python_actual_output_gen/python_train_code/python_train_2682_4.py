# import sys
# sys.stdin = open("test.txt", 'r')

for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))

    a = [p[0]]
    for i in range(2, n-1):
        if p[i] > p[i-1] and p[i] > p[i+1] or p[i] < p[i-1] and p[i] < p[i+1]:
            a.append(p[i])
    a.append(p[-1])

    print(len(a))
    print(*a)
