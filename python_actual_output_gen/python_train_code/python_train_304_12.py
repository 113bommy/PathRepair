def goodnumber(n,k):
    n=str(n)
    n1=list(n)
    n2=set(n1)
    op=list(n2)
    count=0
    

    for i in op:
        if int(i) > k:
            return False

        elif int(i) <=k:
            count+=1



    if count==k+1:
        return True

    else:
        return False



def checker(t,k):
    ans=0
    for i in range(t):
        n=int(input())

        if goodnumber(n,k):
            ans+=1


    print(ans)


t,k=map(int,input().split())
checker(t,k)

