def solve(b):
    n = 2 ** 8
    ans = 0
    while n > 0:
        m = int(bin(n).replace("0b", ""))
        ans += (m <= b)
        n -= 1
    return ans
print (solve(int(input())))