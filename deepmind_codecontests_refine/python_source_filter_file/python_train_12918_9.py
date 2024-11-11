from sys import stdin, stdout
input = lambda: stdin.readline().rstrip()
write = stdout.write

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    if K == 1:
        print(1)
        print(N)
        return

    a = sorted(A, reverse=1)
    num, profit = [0], 0
    for i in range(K):
        profit += a[i]
        j = A.index(a[i])
        num.append(j + 1)
        A[j] = 0
    num.sort()
    num[-1] += N - num[-1]
    print(profit)
    print(*[num[i+1] - num[i] for i in range(K)])

main()
