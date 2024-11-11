if __name__=='__main__':
    N = int(input())
    arr = input().split(' ')
    L = []
    for a in arr:
        L.append(int(a))
    arr = input().split(' ')
    x = int(arr[0])
    y = int(arr[1])
    cs = 0
    cL = []
    for a in L:
        cs+=a
        cL.append(cs)
    ans = 0
    for i in range(len(L)-1):
        if max(cL[i],cs-cL[i])<=y and min(cL[i],cs-cL[i])>=x:
            ans = i+2
            break
    print(ans)
