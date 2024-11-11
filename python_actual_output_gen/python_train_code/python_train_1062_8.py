a,b,n=map(int, input().strip().split(' '))
f=0
if b==5 or b==10:
    print(str(a)+'0'*n)
else:
    for j in range(n):
        p1=(a*10)%b
        if (b-p1)>9 and p1!=0:
            f=1
            print(-1)
            break
        elif p1==0:
            print(str(a)+'0'*(n-j))
            f=1
            break
        else:
            a=a*10+(b-p1)
        print(a)
        
        
            
    if f==0:
        print(a)