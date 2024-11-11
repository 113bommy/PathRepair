import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    MOD = 2**89-1
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]
    NI = lambda : int(sys.stdin.readline())

    N = NI()
    a = LI()
    b = LI()

    ax = []
    bx = []
    for i in range(N):
        ax.append(a[i-1] ^ a[i])
        bx.append(b[i-1] ^ b[i])

    az = 0
    bz = 0
    m = 2**30
    for i in range(N):
        az = (az * m + ax[i]) % MOD
        bz = (bz * m + bx[i]) % MOD

    for i in range(N):
        if az == bz:
            print(i,a[i] ^ b[0])
        az = ((az - ax[i] * pow(m,N-1,MOD)) * m + ax[i]) % MOD

if __name__ == '__main__':
    main()