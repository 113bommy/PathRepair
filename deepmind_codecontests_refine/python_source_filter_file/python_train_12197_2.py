n=int(input())
if(n<25):
    print(-1)
else:
    row=-1
    col=-1
    for i in range(5,n):
        if(n%i==0 and i>=5):
            row=i
            col=n//i
            break
    if(row==col==-1):
        print(-1)
    else:
        arr=['aeiou','eioua','iouae','ouaei','uaeio']
        ans=''
        count1=0
        for i in range(row):
            count=0
            j=0
            while(count<col):
                ans+=arr[count1][j]
                count+=1
                j+=1
                j=j%5
            count1+=1
            count1=count1%5
        print(ans)
    
