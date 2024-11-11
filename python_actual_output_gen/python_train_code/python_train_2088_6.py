N=int(input())
while N>0:
    n=int(input())
    if n%2==0:
        ch=str(1)*int(n/2)
        print(ch)
    elif n==3:
        print(7)
    else:
        ch=str(7)
        ch+=str(1)*int(n/2)
        print(ch)
    N-=1