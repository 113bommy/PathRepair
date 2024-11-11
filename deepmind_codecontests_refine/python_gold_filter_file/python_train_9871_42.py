def main():
    n = int(input())
    H = list(map(int, input().split()))
    A = list(map(int, input().split()))

    def segfunc(x, y):
        if x >= y:
            return x
        else:
            return y

    def init(init_val):
        # set_val
        for i in range(n+1):
            seg[i+num-1] = init_val[i]
        # built
        for i in range(num-2, -1, -1):
            seg[i] = segfunc(seg[2*i+1], seg[2*i+2])

    def update(k, x):
        k += num - 1
        seg[k] = x
        while k:
            k = (k-1)//2
            seg[k] = segfunc(seg[2*k+1], seg[2*k+2])

    def query(p, q):
        if q <= p:
            return ide_ele
        p += num - 1
        q += num - 2
        res = ide_ele
        while p < q:
            if p&1 == 0: #左のnode: == 1, 右のnode: == 0
                res = segfunc(res, seg[p])
            if q&1 == 1: #左のnode: == 1, 右のnode: == 0
                res = segfunc(res, seg[q])
                q -= 1 # 隣に移動
            p = p//2 # 隣のnodeの親にアクセス
            q = (q-1)//2 #親のnodeにアクセス
        if p == q:
            res = segfunc(res, seg[p])
        else:
            res = segfunc(segfunc(res, seg[p]), seg[q])
        return res

    # identity element
    ide_ele = 0

    # num: n以上の最小の2のべき乗
    num = 2**n.bit_length()
    seg = [ide_ele]*2*num

    X = [0]*(n+1)
    for i in range(n):
        update(H[i], query(0, H[i]+1)+A[i])
    print(query(0, n+2))

if __name__ == '__main__':
    main()