USE_STDIO = False

if not USE_STDIO:
    try: import mypc
    except: pass

def getXor(a):
    ans = 0
    for x in a:
        ans ^= x
    return ans

def main():
    n, m = map(int, input().split(' '))
    a = [x for x in map(int, input().split(' '))]
    b = [x for x in map(int, input().split(' '))]

    rxor = getXor(a)
    cxor = getXor(b)

    if rxor != cxor:
        print('NO')
        return
    
    x = [[0] * m for _ in range(n)]

    if n >= m:
        x[0][0] = a[0]
        for i in range(1, m):
            x[i][i-1] = b[i-1] ^ x[i-1][i-1]
            x[i][i] = a[i] ^ x[i][i-1]
        for i in range(m, n):
            x[i][-1] = a[i]
    else:
        x[0][0] = b[0]
        for i in range(1, n):
            x[i-1][i] = a[i-1] ^ x[i-1][i-1]
            x[i][i] = b[i] ^ x[i-1][i]
        for i in range(m, n):
            x[-1][i] = b[i]

    print('YES')
    for i in range(n):
        print(' '.join(map(str, x[i])))

if __name__ == '__main__':
    main()



