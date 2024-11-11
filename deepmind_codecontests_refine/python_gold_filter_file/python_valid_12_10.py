
N = 104

def printResult():
    for j in range(n):
        x = 0
        for i in range(m):
            if a[i][j] != 0:
                x += 1
            else:
                if x % 2 == 1:
                    print("NO")
                    return
                break
    print("YES")

if __name__ == '__main__':
    test = int(input())
    for _ in range(test):
        m, n, k = map(int, input().split())
        if m % 2 == 1:
            tmp = m
            m = n
            n = tmp
            k = m * n // 2 - k
        a = [[0 for k in range(N)] for k in range(N)]
        for i in range(0, m, 2):
            if n > 1:
                for j in range(0, n - 1, 2):
                    if k == 0:
                        break
                    a[i][j] = a[i][j + 1] = k
                    k -= 1
                    if k == 0:
                        break
                    a[i + 1][j] = a[i + 1][j + 1] = k
                    k -= 1
                    if k == 0:
                        break
            if k == 0:
                break
        if k > 0:
            print("NO")
        else:
            printResult() 