n=int(input())
flg=0
for i in range(2,n+1):
    if n%i==0:
        if flg==0:
            print(i,n//i,sep='')
            flg=1