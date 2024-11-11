import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]
    NI = lambda : int(sys.stdin.readline())

    N = NI()
    A = LI()

    x = 0
    for i in A[2:]:
        x ^= i

    s = A[0] + A[1]
    if s - x < 0 or (s - x) % 2:
        print(-1)
        return

    a = (s-x)//2
    if a & x:
        print(-1)
        return

    b = 1 << (A[0].bit_length() - 1)
    while b > 0:
        if b & x and a + b <= A[0]:
            a += b
        b >>= 1
    if a > 0:
        print(A[0] - a)
    else:
        print(-1)


if __name__ == '__main__':
    main()