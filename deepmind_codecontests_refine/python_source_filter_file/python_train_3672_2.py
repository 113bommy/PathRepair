def iin(): return int(input())


def lin(): return list(map(int, input().split()))
def main():
    n = iin()
    a = lin()
    dp = [0 for i in range(n)]
    left_less = [-1] * n
    left_greater = [-1] * n
    right_less = [-1] * n
    right_greater = [-1] * n
    # left less
    stack = []
    for i in range(n):
        while stack and stack[-1][0] < a[i]:
            stack.pop()

        if stack:
            left_less[i] = stack[-1][1]
        stack.append([a[i], i])
    # right less
    stack = []
    for i in range(n - 1, -1, -1):
        while stack and stack[-1][0] < a[i]:
            stack.pop()

        if stack:
            right_less[i] = stack[-1][1]
        stack.append([a[i], i])

    # left greater
    stack = []
    for i in range(n):
        while stack and stack[-1][0] > a[i]:
            stack.pop()

        if stack:
            left_greater[i] = stack[-1][1]
        stack.append([a[i], i])
    # right greater
    stack = []
    for i in range(n - 1, -1, -1):
        while stack and stack[-1][0] > a[i]:
            stack.pop()

        if stack:
            right_greater[i] = stack[-1][1]
        stack.append([a[i], i])
    print(left_less)
    print(left_greater)
    print(right_greater)
    print(right_less)
    points = [[] for i in range(n)]
    for i in range(n):
        if left_less[i] != -1:
            points[left_less[i]].append(i)
        if left_greater[i] != -1:
            points[left_greater[i]].append(i)
        if right_less[i] != -1:
            points[i].append(right_less[i])
        if right_greater[i] != -1:
            points[i].append(right_greater[i])
    print(points)

    # dp[i] = minimum jumps to reach i th position
    dp[0] = 0
    # print(points, left_greater, left_less, right_greater, right_less)
    for i in range(n):
        for p in points[i]:
            dp[p] = min(dp[p], dp[i] + 1)
            print(dp)
        # print(dp)

    print(dp[n - 1])


main()