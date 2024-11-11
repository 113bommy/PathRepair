n,m=map(int,input().strip().split(' '))
li=list(int(i) for i in input().strip().split(' '))
s=sum(li)
count=0 
ma=0
for i in range(n):
    x=int(li[i]/m)
    print(x)
    if li[i]%m==0:
        
        if x>=ma:
            count=i 
            ma=x 
    else:
        if x+1>=ma:
            count=i 
            ma=x+1
print(n) if ma==0 else print(count+1)
        