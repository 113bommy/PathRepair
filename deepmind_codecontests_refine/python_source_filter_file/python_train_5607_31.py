def solve():
    x, y = map(int, input().split())
    print(min(abs(y - x) + (2 if y < 0 else 0), abs(y + x + 1)))

if __name__=="__main__":
    solve()