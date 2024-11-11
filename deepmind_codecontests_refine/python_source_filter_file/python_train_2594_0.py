while True:
    w,d = [int(i) for i in input().split()]
    if w == 0:
        break
    h = [int(i) for i in input().split()]
    h_ = [int(i) for i in input().split()]
    h = sorted(h)
    h_ = sorted(h_)
    hdic = {}
    h_dic = {}

    for i in h:
        if i in hdic.keys():
            hdic[i]+= 1
        else:
            hdic[i] = 1
    
    for i in h_:
        if i in h_dic.keys():
            h_dic[i]+= 1
        else:
            h_dic[i] = 1
    ans  = sum(h)+ sum(h_)
    for num in hdic.keys():
        if num in h_dic.keys():
            ans -= num*min(hdic[i],h_dic[i])
    print(ans)

