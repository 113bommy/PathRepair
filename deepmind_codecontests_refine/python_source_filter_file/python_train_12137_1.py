n=int(input())
rdl = list(map(int, input().split()))
if rdl[0]==0:
    print(-1)
else:
    summ=0
    for i in range(len(rdl)):
        summ=summ+rdl[i]
    if summ<n:
        print(-1)
    else:
        b=[]
        for i in range(n-1):
            b.append([0]*2)
            b[i][0]=rdl[i+1]
            b[i][1]=i+2
        b.sort()
        b.reverse()
        b.insert(0,[rdl[0],1])
        k=0
        j=0
        print(n-1)
        l=j+1
        while k!=n-1:
            while b[j][0]>0 and k!=n-1:
                print(b[j][1],b[l][1])
                b[j][0]-=1
                l+=1
                k+=1
            j+=1

                   
