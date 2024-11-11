#coding: utf-8

def main():
    N = int(input())
    t = list(map(int, input().split()))
    a = list(reversed(list(map(int, input().split()))))

    m = [0] * N

    b = 0
    for i,h in enumerate(t):
        if b != h:
            m[i] = h#確定
            if a[i] < h:
                print(0)
                return
        b = h
    b = 0
    for j,h in enumerate(a):
        p = N-j-1
        if b != h:
            if m[p] != 0 and m[p] != h:
                print(0)
                return
            else:
                m[p] = h#確定
                if t[p] < h:
                    print(0)
                    return
        b = h
    res = 1
    for k,h in enumerate(m):
        if h == 0:
            res = res * min(a[N-k-1], t[k]) % (pow(10, 9) + 7)
    print(res)
    return

main()
