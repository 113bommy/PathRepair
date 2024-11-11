n,m=map(int,input().split())
a='#'*(m)
b='.'*(m-1)+'#'
c='#'*m
d='#'+'.'*(m-1)
l=[a,b,c,d]
for i in range(n):
    if(m<=4):
        print(l[i%m])
    else:
        print(l[i%4])
