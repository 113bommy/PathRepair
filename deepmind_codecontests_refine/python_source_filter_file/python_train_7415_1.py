#author: riyan

if __name__ == '__main__':
    n, k = map(int, input().strip().split())
    arr = list(map(int, input().strip().split()))

    md = {}
    for i in range(n):
        md[arr[i]] = i + 1

    mxv = 0
    idx = []
    for i in sorted(md):
       if i > (n - k):
           mxv += i
           idx.append(md[i])

    mxvs = 1
    idx = sorted(idx)
    mod = 988244353
    for i in range(len(idx) - 1, 0, -1):
        tidx = idx[i] - idx[i-1]
        mxvs = ((mxvs % mod) * (tidx % mod)) % mod

    print(mxv, mxvs)
    
    