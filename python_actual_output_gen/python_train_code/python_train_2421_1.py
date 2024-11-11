
def valid(fuses, k, a, b):
    if k > b - a - 1:
        return 0
    i = 0
    for time in range(b - 2, b - 2 - k, -1):
        if i == len(fuses):
            return 0
        while fuses[i] > time:
            i += 1
            if i == len(fuses):
                return 0
        i += 1
    return 1


def binary_search(fuses, a, b) -> int:
    left, right = 0, b 
    while left < right:
        mid = left + (right - left) // 2
        if not valid(fuses, mid, a, b):
            right = mid
        else:
            left = mid + 1
    return left

def solve():
    for _ in range(int(input())):
        n, m, a, b = map(int, input().split())
        if b < a:
            a = n - a 
            b = n - b
        fuses = sorted(list(map(int, input().split())), reverse=True)
        print(max(binary_search(fuses, a, b) - 1, 0))

solve()



