def solve(n):
    k = (n - 1) // 4 + 1
    return "9" * (n - k) + "8" * k
def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        print(solve(n))
main()
