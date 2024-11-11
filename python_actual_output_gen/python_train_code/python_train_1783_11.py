if __name__=="__main__":
    n,m=input().split()
    n,m=int(n),int(m)
    tv=list(map(int,input().split()))
    negPrice=[x for x in tv if x<0]
    negPrice.sort()
    gain=0
    i=0
    while i<len(negPrice) and i<m: gain+=negPrice[i];i+=1
    print(gain)

