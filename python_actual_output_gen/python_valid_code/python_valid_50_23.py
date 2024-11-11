tests = int(input())
for tst in range(tests):
    a, b, c = map(int, input().split())
    ans1, ans2 = -1, -1
    if a < c:
        ans1 = 1
    if c < a * b:
        ans2 = 1
    print(ans1, ans2)
