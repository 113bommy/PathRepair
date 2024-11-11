def main():
    n, k =  map(int, input().strip().split())
    return list(range(n, n - 2, -1)) + list(range(1, n - 1))


print(*main())