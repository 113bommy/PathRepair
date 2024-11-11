import sys

read = sys.stdin.readline

for _ in range(int(read())):
    n = int(read())
    arr = list(map(int, read().split()))

    ans = [0, 0, 0]
    for i in range(n):
        mod = arr[i]%3
        ans[mod] += 1
    
    while ans[1] and ans[2]:
        ans[1] -= 1
        ans[2] -= 1
        ans[0] += 1

    if ans[1]: ans[0] += ans[1]//3
    if ans[2]: ans[0] += ans[2]*2//3

    print(ans[0])
