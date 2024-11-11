from sys import stdin, stdout
def main():
    n, m, k = map(int, stdin.readline().rstrip().split())
    B1 = [[0, 0, 0, 0] for i in range(n)]
    B2 = [[0, 0, 0, 0] for i in range(m)]
    for i in range(k):
        a, b, c = map(int, stdin.readline().rstrip().split())
        b -= 1
        if a == 1:
            B1[b] = [i, a, b, c]
        else:
            B2[b] = [i, a, b, c]

    C = sorted(B1 + B2, key = lambda x: x[0])

    A = [[0] * m for i in range(n)]
        
    for i in range(len(C)):
        x, a, b, c = C[i]
        if a == 1:
            A[b] = [c] * m
        elif a == 2:
            for j in range(n):
                A[j][b] = c
    for row in A:
        stdout.write(' '.join(map(str, row)))


main()