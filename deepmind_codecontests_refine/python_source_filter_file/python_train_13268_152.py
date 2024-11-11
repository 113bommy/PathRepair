def solve():
    count = 0
    for i in range(int(input())):
        p, q = list(map(int, input().split()))
        if p < q:
            count += 1
    print(count)
if __name__ == "__main__":
    solve()
