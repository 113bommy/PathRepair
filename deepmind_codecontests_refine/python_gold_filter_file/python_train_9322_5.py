def checkNumberOfShops(money,price_in_each_shop):
    global dict
    l=0
    f=0
    r=len(price_in_each_shop)-1
    n=len(price_in_each_shop)
    if(money<price_in_each_shop[0]):
        return 0
    elif(money>=price_in_each_shop[-1]):
        return n
    else:
        while(l<=r):
            m=int((l+r)/2)
            if(money>price_in_each_shop[m]):
                l=m+1
            elif(money<price_in_each_shop[m]):
                r=m-1
            else:
                f=1
                break
        if(f==1):
            while(m+1 != n):
                if(price_in_each_shop[m+1]!=money):
                    break
                m+=1
            dict[money]=m+1
            return m+1
                
        if(l>m):
            dict[money]=m+1
            return m+1
        if(r<m):
            dict[money]=m
            return m
    


if __name__ == "__main__":
    global dict
    dict={}
    number_of_shops=int(input())
    price_in_each_shop=list(map(int,input().split()))
    price_in_each_shop.sort()
    no_of_days=int(input())
    for i in range(no_of_days):
        t=int(input())
        if(t in dict):
            print(dict[t])
        else:
            print(checkNumberOfShops(t,price_in_each_shop))
        