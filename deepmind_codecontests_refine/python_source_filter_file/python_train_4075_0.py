def main():
    int(input())
    a = [0] * 10010
    n = -1e9
    for i in map(int, input().split()):
        a[i] += 1
        n = max(n, i)
    i = 1
    while i * i < n:
        if n % i == 0:
            a[i] -= 1
            a[n // i] -= 1
        i += 1
    if n % i == 0:
        a[i] -= 1
    i = 10000
    while a[i] == 0: i -= 1
    print(n, i)
main()
