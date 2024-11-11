from sys import maxsize


def checker(n, lst):
    mx, mn = maxsize, -maxsize
    for i in range(n):
        if i > 0 and lst[i] == -1 and lst[i - 1] != -1:
            mn, mx = min(mn, lst[i - 1]), max(mx, lst[i - 1])
        if i < n - 1 and lst[i] == -1 and lst[i + 1] != -1:
            mn, mx = min(mn, lst[i + 1]), max(mx, lst[i + 1])
    result, answer = (mx + mn) // 2, 0
    for i in range(n):
        if lst[i] == -1:
            lst[i] = result
        if i:
            answer = max(answer, abs(lst[i] - lst[i - 1]))
    return answer, result


for _ in range(int(input())):
    m = int(input())
    a = [int(j) for j in input().split()]
    print(*checker(m, a))
