

def solve():
    n = int(input())
    for i in range(n):
        x = int(input())
        if x > 2:
            print(x//2)
        else:
            print(0)


if __name__ == "__main__":
    solve()