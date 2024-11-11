n=int(input())
a=n//7
b=0
while(1):
    if a==-1:
        print(-1)
        exit(0)
    if (n-7*a)%4==0:
        b=(n-7*a)//4
        break
    a-=1
print('4'*a+'7'*b)    