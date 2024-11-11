import sys

input = sys.stdin.readline
t = int(input())
for trial in range(t):
    n, m = (map(int, input().split()))
    both = []
    for i in range(m):
        a1, b1 = map(int, input().split())
        both.append([a1, b1])
    if trial < t-1:
        input()
    ans = 0
    sort_by_a = sorted(both, key=lambda x: (x[0], x[1]), reverse=True)
    sort_by_b = sorted(both, key=lambda x: (x[1], x[0]), reverse=True)
    sum_of_a = 0
    a_index = 0
    max_b = 0
    for i in range(m):
        while a_index < m and sort_by_a[a_index][0] > sort_by_b[i][1]:
            sum_of_a += sort_by_a[a_index][0]
            max_b = max(sort_by_a[a_index][1], max_b)
            a_index += 1
            if a_index == n or a_index == m:
                break
        if a_index == n or sort_by_b[i][1] < max_b:
            ans = max(sum_of_a, ans)
            break
        if sort_by_b[i][0] > sort_by_b[i][1]:
            ans = max(ans, sum_of_a + (n - a_index)*sort_by_b[i][1])
        else:
            ans = max(ans, sum_of_a + (n - a_index - 1) * sort_by_b[i][1] + sort_by_b[i][0])
    print(ans)
    '''if n == 1:
        for i in range(m):
            print(sort_by_b[i][0], sort_by_b[i][1])
        for i in range(m):
            print(sort_by_a[i][0], sort_by_a[i][1])'''
