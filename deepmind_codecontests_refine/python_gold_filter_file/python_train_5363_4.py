def splitt():
        n, p, q = map(int,input().split())
        ch = input()
        test=False
        for i in range (0,n+1):
                for j in range(0,n+1):
                        if (i*p+j*q)==n:
                                test=True
                                break
        if test==False:
                print(-1)
        if test==True:
                for k in range(n):
                        if n-k*p < 0:
                                break
                        if (n-k*p)%q==0:
                                z = (n-k*p)//q
                                ind=0
                                T=[]
                                for i in range(k):
                                        T.append(ch[ind:ind+p])
                                        ind += p
                                for i in range(z):
                                        T.append(ch[ind:ind+q])
                                        ind += q
                                print(len(T))
                                for j in T:
                                        print(j)
                                return
splitt()