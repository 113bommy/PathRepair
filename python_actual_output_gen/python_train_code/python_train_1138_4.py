for _ in range (int(input("t = "))):
    n,m = map(int,input().split())
    k_num = list(map(int,input().split()))
    k_num = sorted(k_num , reverse=True)
    price_gift = list(map(int,input().split()))
    res = 0 ; j = 0
    for i in k_num :
        if j < i : res+= price_gift[j];j+=1
        else : res+= price_gift[i-1]
    print(res)