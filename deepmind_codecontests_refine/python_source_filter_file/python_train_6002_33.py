n,m=list(map(int,input().strip().split()))
t=0
for j in range(n):
    if t>0:
        break
    else:
        for k in range(1,n+1):
            m=m-k
            if m==0:
                t +=1
                print("0")
                break
            elif m<0:
                t +=1
                print(m+k)
                break
