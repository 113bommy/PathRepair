def process(key, a,b,p, k,n):

    nc=[b[i]-(a[i]*key) for i in range(n)]
    #print(key, nc, end=" ")
    c=0
    for i in range(n):
        if nc[i]<0:
            c+=p[i]*nc[i]*-1
    k-=c
    #print(k)
    if k>=0:
        return True
    else:
        return False


def bin_src(a,b,p,n,k,lo,hi):
    while (hi-lo>1):
        mid = ((hi +lo) // 2)
        val = process(mid,a,b,p,k,n)
        if val==True:
            lo=mid
        else:
            hi=mid

    if(process(lo,a,b,p,k,n)==True):
        return lo
    else:
        return hi


def main():
    s = input()
    b=list(map(int,input().split(" ")))
    a=[0,0,0]
    for i in s:
        if i=='B':
            a[0]+=1
        elif i=='S':
            a[1]+=1
        else:
            a[2]+=1

    p=list(map(int,input().split(" ")))
    k=int(input())
    print(bin_src(a,b,p,3,k, 0, ((10**12))))

if __name__=="__main__":
    main()

