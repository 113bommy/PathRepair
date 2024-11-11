
if __name__ == '__main__':
    k = int(input())
    mod = k % 1500
    a = 1500 - mod
    x = 1500
    z = (k + a) // 1500 + a
    print(x + 1)
    ans = [0] * (x -1) + [a, z]
    print(*ans)