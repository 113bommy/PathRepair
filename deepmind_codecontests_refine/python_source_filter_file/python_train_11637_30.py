import sys
import heapq


# \n
def input():
    return sys.stdin.readline().rstrip()


def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    def diff(s,cc):
        count = 0
        for i in range(N):
            if A[i] == B[(i + s) % N]:
                count += 1
                if count>cc:
                    return cc+1
        if count == 0:
            print("Yes")
            L = []
            for i in range(N):
                L.append(B[(i + s) % N])
            print(*L)
            exit()

        return count
    n = N // 3
    l = 0
    r = N - 1
    diff(l,0)
    diff(r,0)

    while r - l > 2:
        m1 = l + (r - l) // 3
        m2 = l + 2 * (r - l) // 3
        a = diff(m1,0)
        b = diff(m2,a)
        if a > b:
            l = m1
        else:
            r = m2
    diff((l + r) // 2,0)

    print("No")


if __name__ == "__main__":
    main()
