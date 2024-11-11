def main():
    n=int(input())
    ga,sa,ba=map(int,input().split())
    gb,sb,bb=map(int,input().split())
    
    def calc_1(dg,a0,a1):
        return (dg//a0)*a1+dg%a0

    def calc_2(dg,a0,a1,b0,b1):
        x=dg//a0
        visit=set()
        temp=0
        for i in range(x,-1,-1):
            amari=(dg-x*a0)%b0
            if amari in visit:
                break
            temp=max(x*a1+((dg-x*a0)//b0)*b1+amari,temp)
            visit.add(amari)
        return temp

    #def calc_3(dg,a0,a1,b0,b1,c0,c1):
    #    return max([a1*i+calc_2(dg-a0*i,b0,b1,c0,c1) for i in range(dg//a0,-1,-1)])

    gsb=[[ga,gb],[sa,sb],[ba,bb]]
    gsb.sort(key=lambda x:x[1]/x[0],reverse=True)
    temp=[[i,j] for i,j in gsb if i<j]
    if len(temp)==1:
        n=calc_1(n,temp[0][0],temp[0][1])
    elif len(temp)==2:
        n=calc_2(n,temp[0][0],temp[0][1],temp[1][0],temp[1][1])
    elif len(temp)==3:
        n=calc_3(n,temp[0][0],temp[0][1],temp[1][0],temp[1][1],temp[2][0],temp[2][1])

    gsb=reversed(gsb)
    temp=[[j,i] for i,j in gsb if i>j]
    if len(temp)==1:
        n=calc_1(n,temp[0][0],temp[0][1])
    elif len(temp)==2:
        n=calc_2(n,temp[0][0],temp[0][1],temp[1][0],temp[1][1])
    elif len(temp)==3:
        n=calc_3(n,temp[0][0],temp[0][1],temp[1][0],temp[1][1],temp[2][0],temp[2][1])
    print(n)
main()