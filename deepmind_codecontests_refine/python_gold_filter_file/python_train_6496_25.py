if __name__=='__main__':
    inp = input()
    arr = inp.split()
    n = int(arr[0])
    m = int(arr[1])
    inp = input()
    arr = inp.split()
    L = []
    for a in arr:
        L.append(int(a))
    st = 0
    pr = 1
    ans = 0
    bst = True
    while (st+1)<m:
        if L[st]>L[st+1]:
            if bst:
                ans+=L[st]-pr
                bst=False
            else:
                ans+=L[st]-pr+n
            pr = L[st]
        
        st+=1
    if bst:
        ans+=L[st]-1
    else:
        ans+=L[st]-pr+n
    print(ans)
