n=int(input())
if n>=0:
    print(n)
else:
    a=(n+(-n)%10)/10
    c=(-a)%10
    n=max((n+(-n)%10)/10,a+c-(-n)%10)
    print('%d' %(n))
