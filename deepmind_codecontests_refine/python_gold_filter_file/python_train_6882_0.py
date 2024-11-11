x = input().split(" ")
n = eval(x[0])
i=0
while n//(10**i)!=0:
    i+=1
if i==1:
    print(n)
else:
    s=0
    temp = 0
    for j in range(i):
        if j==0:
            if n%10==9:
                s+=9
            else:
                s+=10+(n%10)
                temp=1
        elif j ==i-1:
            s+=n-temp
        else:
            if n%10==0:
                s+=10-temp
                if temp==0:
                    temp=1
            elif n%10==9 and temp==0:
                s+=9
            else:
                s+= 10+(n%10)-temp
                temp=1
        n= (n-(n%10))/10   
    print((int)(s))
