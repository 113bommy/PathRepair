def solve(n, k):
    low = 0
    high = n  # Try writing max lines first, then reduce
    while low + 1 < high:
        mid = (low+high)//2
        if works(mid, n, k):
            high = mid
        else:
            low = mid
    return high


def works(mid, n, k):
    total_lines_written = mid
    curr_lines = mid
    curr_k = k
    while curr_lines > 0:
        curr_lines = mid//curr_k
        total_lines_written = total_lines_written + curr_lines
        curr_k = curr_k * k
    return total_lines_written >= n


info = [int(num) for num in input().split()]
lines = info[0]
divisor = info[1]

result = solve(lines, divisor)
print(result)
