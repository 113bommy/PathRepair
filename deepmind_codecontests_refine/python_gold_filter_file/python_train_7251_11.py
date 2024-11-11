n,k=map(int,input().split())
hr=[]
mn=[]
s=k*2+2
for i in range(0,n):
    x,y=map(int,input().split())
    hr.insert(i,x)
    mn.insert(i,y)


fst=hr[0]*60+mn[0]

if fst >= k+1:
    print("0 0")
else:
    v=0;
    lst=int(0)
    for j in range(0,n-1):
        fst=hr[j]*60+mn[j]
        lst=hr[j+1]*60+mn[j+1];
        df=lst-fst
        if df>=s:
            v=1
            #print (j)
            break

    if v==1:
        fst+=1+k
        print(fst//60,' ',fst%60)
    else:
        lst=hr[n-1]*60+mn[n-1]+1+k
        print (lst//60,' ',lst%60)