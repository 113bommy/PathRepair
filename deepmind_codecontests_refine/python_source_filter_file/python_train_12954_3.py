n,k = [int(i) for i in input().split()]
if n==1 and k==0:
    print(1)
elif n==1 and k>0:
    print(-1)
elif k<n//2 :
    print(-1)    
elif n>=2:
    if n%2==0:
        m = n-2
        summ = 0
        st = 10**8
        while(m>0):
            print(st,end=' ')
            st+=1
            print(st,end=' ')
            summ+=1
            st+=1
            m-=2
        diff = k-summ
        print(diff,diff*8)
    else:
        m=  n-3
        summ = 0
        st = 10**8
        while(m>0):
            print(st,end=' ')
            st+=1
            print(st,end=' ')
            summ+=1
            st+=1
            m-=2
        diff = k-summ
        print(diff,diff*8,end=' ')
        print(diff+1)