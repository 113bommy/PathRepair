cases = int(input())
tests = []
results = []
for i in range(cases):
    tests.append([int(item) for item in input().split()])
def bs(a, b):
    left, right = 0, a
    while left < right:
        mid = (left + right) // 2
        v1 = a - mid
        v2 = b - 2 * mid
        if v1 == 2 * v2:
            return True
        elif v1 > 2 * v2:
            right = mid - 1
        else:
            left = mid + 1
    return False
for test in tests:
    # #[0] + 2 * [1] = test[0]
    # #2 * [0] + [1] = test[1]
    # #[0] + [1] = test[0] + test[1]
    # #[0] = test[0] - total
    # if sum(test) % 3 != 0:
    #    results.append("NO")
    # else:
    #     total = sum(test) // 3
    #     op1 = test[0] - total
    #     op2 = test[1] - total
    #     if op1 >= 0:
    #         if op2 >= 0:
    #             results.append("YES")
    #         else:
    #             results.append("NO")
    #     else:
    #         results.append("NO")
    if bs(test[0], test[1]):
        results.append("YES")
    else:
        results.append("NO")
for result in results:
    print(result)