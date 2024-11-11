n,s = map(int, input().strip().split(' '))
lst=[]
for i in range(n):
    h,m = map(int, input().strip().split(' '))
    p=h*60 + m
    lst.append(p)
#print(lst)
if lst[0]>s+1:
    print('0 0')
else:
    dif=[]
    f=0
    for i in range(1,n):
        dif.append(lst[i]-lst[i-1])
    #print(dif)
    for i in range(len(dif)):
        if dif[i]>2*s + 1:
            k=lst[i]+s+1
            print(k)
            h=k//60
            m=k%60
            print(h,m,end=" ")
            f=1
            break
    if f==0:
        k=lst[n-1]+1+s
        h=k//60
        m=k%60
        print(h,m,end=" ")
        
        
            
    