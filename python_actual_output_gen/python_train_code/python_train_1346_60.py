n,m=list(map(int,input().split()))
a=',' * (m-1)
b='#'
c='#'*m
for i in range(n):
    if(i%2==0):
        print(c)
    else:
        print("{}{}".format(a, b))
        a, b=b, a