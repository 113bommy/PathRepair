def main():
    input()
    H=map(int,input().split())
    A=map(int,input().split())
    n=10*5+1

    def update_max(k,x):
        k += num_max-1
        seg_max[k] = x
        while k:
            k = (k-1)//2
            seg_max[k] = max(seg_max[k*2+1],seg_max[k*2+2])
    def query_max(p,q):
        if q<=p:
            return ide_ele_max
        p += num_max-1
        q += num_max-2
        res=ide_ele_max
        while q-p>1:
            if p&1 == 0:
                res = max(res,seg_max[p])
            if q&1 == 1:
                res = max(res,seg_max[q])
                q -= 1
            p = p//2
            q = (q-1)//2
        if p == q:
            res = max(res,seg_max[p])
        else:
            res = max(max(res,seg_max[p]),seg_max[q])
        return res
    ide_ele_max = 0
    num_max =2**(n-1).bit_length()
    seg_max=[ide_ele_max]*2*num_max

    for h,a in zip(H,A):
        update_max(h,query_max(0,h)+a)
    
    print(query_max(0,n))
main()