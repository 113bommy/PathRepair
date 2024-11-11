for _ in range(int(input())):
        n=int(input())
        s=input()
        k=s.find('0')
        if k==-1:
                print(1,n//2,n//2+1,n//2*2)
        elif k<n//2:
                print(k+1,n,k+2,n)
        else:
                print(1,k+1,1,k)
