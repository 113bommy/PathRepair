NANS = (False, None)

def is_valid(n, k):
    if n > 17:
        return True
    return k*3 <= (2**(2*n) - 1)


def solve_mini(n, k):
    if not is_valid(n, k):
        return NANS

    if n == 1:
        if k == 1:
            return (True, 0)
        else:
            return (False, None)
    if n == 2:
        if k in [1, 2]:
            return (True, 1)
        if k in [4, 5]:
            return (True, 0)
    return (False, None)



def solve(n, k):
    if n < 3:
        ans, log = solve_mini(n, k)
        return (ans, log)

    # validity of k
    if not is_valid(n, k):
        return NANS

    w = 1
    while k >= w and n >= 1:
        k -= w
        n -= 1
        w = w + w + 1
    return(True, n)


t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    ans, log = solve(n, k)
    if ans:
        print("YES", log)
    else:
        print("NO")

