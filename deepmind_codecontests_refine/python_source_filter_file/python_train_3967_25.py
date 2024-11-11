n,m=map(int,input().split())
if(m>=2*n):
    print('1'*n)
    print('1'*(n-2)+'0'+'2')
elif(m<n):
    print('1'*n)
    if(m==1):
        print('8'*(n-1)+'9')
    elif(m==2):
        print('8'*(n-2)+'9'+'0')
    else:
        print('8'*(n-m)+'9'+'0'*(n-(n-m+1)))
else:
    print('1'*n)
    ans=0
    k1=''
    count=0
    while(count+2<m):
        k1+='1'
        count+=2
    k1+='8'*(n-len(k1)-1)+'9'
    print(k1)


