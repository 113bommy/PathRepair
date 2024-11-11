import math
def main():
    n = int(input())
    l = list(map(int, input().split()))
    c = 0
    while max(l) > n-1:
        l.sort(reverse=True)
        tc = [0] * n
        for i in range(n):
            if l[i] >= n:
                tc[i] = math.ceil((l[i] - n + 1)/n)
                l[i] -= tc[i] * n
        stc = sum(tc)
        for i in range(n):
            l[i] += stc - tc[i]
        c += stc
    return c
print(main())
