n,k = [int(x) for x in input().split()]
def DTB(num,x): 
    if num > 1: 
        DTB(num // 2,x) 
    x.append(num % 2)
nn=[]
kk=[]
DTB(n,nn)
DTB(k,kk)
if k==1:
    print(n)
elif k==2:
    if n==2:
        print(1)
    else:
        if n%2==0:
            print(n-2)
        else:
            print(n-1)
elif k==3:
    if n%4==2:
        print(n//2-1)
    else:
        print(n//2)
else:
    a = len(kk)-2
    m = len(nn)
    p = 2**(a+1)-1 + (n%(2**a))
    if nn[m-a-1]==1:
        p += 2**(a)
    if p>=k:
        print(int(''.join([str(x) for x in nn[0:(m-a-1)]])+'0', 2))
    else:
        N = nn[0:m-a-1]
        if sum(N)>2:
            if k==(2**(a+2)-1):
                if sum(nn[m-a-1:m])==a+1:
                    print(int(''.join([str(x) for x in nn[0:m-a-1]]), 2))
                else:
                    print(int(''.join([str(x) for x in nn[0:m-a-2]])+'0', 2))             
            else:
                N.reverse()
                ind = N.index(1)
                N[ind]=0
                for i in range(ind):
                    N[i]=1
                N.reverse()
                N.append(0)
                print(int(''.join([str(x) for x in N]), 2))
        else:
            if m-a-1==1:
                print(1)
            else:
                if k!= (2**(a+2)-1):
                    print(2**(m-a-1)-2)
                else:
                    print(2**(m-a-2))