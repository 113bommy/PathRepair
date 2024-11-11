n=list(input())
n=n[::-1]
for i in n:

    if int(i)>=5:
        a=int(i)-5
        b=5-(a+1)
        print('-'+'o'+'|'+'o'*a+'-'+'o'*b)
    else:
        a=int(i)
        b=5-(a+1)
        print('o'+'-'+'|'+'o'*a+'-'+'o'*b)
