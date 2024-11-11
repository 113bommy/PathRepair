def sol():
    n=int(input())
    A=input()
    B=[0]*10
    lc,rc=0,9
    for c in A:
        if(c=='L'):
            lc=0
            while(lc<=9 and B[lc]!=0):
                lc+=1
            B[lc]=1
        elif(c=='R'):
            rc=9
            while(lc>=0 and B[rc]!=0):
                rc-=1
            B[rc]=1
        else:
            p=int(c)
            B[p]=0
    print(*B,sep="")
if(__name__=='__main__'):
    sol()
