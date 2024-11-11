for i in range(int(input())):
    n = int(input())
    ans = [ [0] * n for i in range(n)]
    s = (('1 2'+' 0'*(n-2)) + ' ') * 2
    index = 0
    for i in range(n):
        ans[i] = list(map(int, s[index: index + 2 * (n - 1) + 1].split()))
        index += 2
    for i in ans:
        print(*i)
