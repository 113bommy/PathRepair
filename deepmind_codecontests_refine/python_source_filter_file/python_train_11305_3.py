
def main(n, k):
    total = n*n
    if total < k:
        print(-1)
        return

    m = [[0]*n for _ in range(n)]
    fill(m, n, k)
    print_m(m)

def fill(m, n ,k):
    for i in range(n):
        for j in range(i, n):
            if k == 0:
                return

            if i == j:
                m[i][j] = 1
                k -= 1
            elif k == 1:
                m[i+1][i+1] = 1
                k = 0
                return
            else:
                m[i][j] = 1
                m[j][i] = 1
                k -= 2

def print_m(m):
    for row in m:
        print(' '.join(map(str, row)))


n, k = [int(x) for x in input().split()]
main(4, k)
