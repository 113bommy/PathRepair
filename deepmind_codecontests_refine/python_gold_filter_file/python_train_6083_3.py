t=int(input())
for i in range(t):
        n,p=map(int,input().split())
        c=0
        z=(2*n)+p
        #print(z)
        for i in range(1,n+1):
                for j in range(i+1,n+1):
                        if(c>=z):
                                break
                        else:
                                print(i,j)
                                c=c+1

