n=int(input())
a=n//4
b=0
while(1):
    if a==-1:
        print(-1)
        exit(0)
    if (n-4*a)%7==0:
        b=(n-4*a)//7
        break
    a-=1
print('4'*a+'7'*b)    