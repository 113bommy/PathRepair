from bisect import bisect_left as lower_bound, bisect_right as upper_bound
from sys import stdin, stdout
from collections import defaultdict

N = 10**5 + 7

minn = [0 for _ in range(2*N)]
maxx = [0 for _ in range(2*N)]

def build(p, n):
    for i in range(n): 
        maxx[n+i] = p[i]
        minn[n+i] = p[i]

    for i in range(n-1, 0, -1):
        maxx[i] = max(maxx[i<<1], maxx[i<<1|1])
        minn[i] = min(minn[i<<1], minn[i<<1|1])

def query(l, r, n):
    l += n
    r += n

    retminn, retmaxx = float('inf'), -float('inf')

    while l < r:
        if l&1:
            retminn = min(retminn, minn[l])
            retmaxx = max(retmaxx, maxx[l])
            l += 1

        if r&1:
            r -= 1
            retminn = min(retminn, minn[r])
            retmaxx = max(retmaxx, maxx[r])

        l >>= 1
        r >>= 1

    return retminn, retmaxx


def main():
    n = int(input())
    a = list(map(int, input().strip().split()))

    left = [-1]*n
    right = [n]*n

    p = [a[i] for i in range(n)]
    for i in range(1, n): p[i] += p[i-1]

    build(p, n)

    st = [0]
    for i in range(1, n):
        while st and a[st[-1]] <= a[i]: st.pop()

        if st: left[i] = st[-1]
        st.append(i)

    st = [n-1]
    for i in range(n-2, -1, -1):
        while st and a[st[-1]] < a[i]: st.pop()

        if st: right[i] = st[-1]
        st.append(i)

    #print(left, right, p)
    #
    
    if max(a) <= 0:
        print(0)
        return None

    ret = -float('inf')

    for i in range(n):
        l, r = left[i], right[i]

        _, rmaxx = query(i, r, n)
        lminn, _ = query(max(0, l), i, n)

        if l < 0: lminn = min(lminn, 0)

        s = rmaxx - lminn
        #print(i, s, a[i], l, r)

        ret = max(ret, s-a[i])

    print(ret)



if __name__ == "__main__": main()
