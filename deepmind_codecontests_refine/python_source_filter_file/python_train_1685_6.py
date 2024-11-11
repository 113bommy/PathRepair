from sys import stdin,stdout
input = stdin.readline
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    m = arr[-1];    cnt = 0
    for i in range(n-2,-1,-1):
        if arr[i] >= m:
            cnt += 1
        if arr[i] < m:
            m = arr[i]
    print(cnt)