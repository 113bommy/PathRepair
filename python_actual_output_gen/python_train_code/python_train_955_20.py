t = int(input())


def solve_arr(a):
    for i in range(len(a) - 1):
        if abs(a[i] - a[i + 1]) >= 2:
            print("YES")
            print(i, i + 1)
            return
    print("NO")


for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    solve_arr(a)
