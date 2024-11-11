import sys

input = sys.stdin.readline

def main():
    MOD = 10 ** 9 + 7
    N = int(input())

    fact = [1, 1]
    for i in range(2, N + 1):
        fact.append((fact[-1] * i) % MOD)

    print(fact[N] - pow(2, N - 1, MOD))


if __name__ == '__main__':
    main()
