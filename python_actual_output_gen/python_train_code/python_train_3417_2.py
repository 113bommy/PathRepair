t=int(input(''))
for i in range (1,t+1):
    n,x=[int(n)for n in input('').split()]
    n=n-2
    if n>=1 :
        floor=((n+x-1)//x)
        print(floor+1)
    else :
        print(n+2)