





n,k,t = map(int,input().split())



x = t/100


u = n*k
d=[]

if k*n/u<=t/100:
    print(*([k]*n))
else:
    for i in range(1,n):
        a=k*i
        if a/u<x:
            #print(a/u,x)
            d.append(k)
        else:
            if a/u==x:
                d.append(k)
                print(*(d+[0]*(n-len(d))))
                break
            else:
                a-=k
                for j in range(1,k+1):
                    if (a+j)/u<=x<(a+j+1)/u:
                        d.append(j)
                        break

                print(*(d+(n-len(d))*[0]))
                break
