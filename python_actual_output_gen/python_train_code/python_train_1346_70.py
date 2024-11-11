m,n=input().split(' ')
m=int(m)
n=int(n)
t1=''
t2=''
t3='#'
for i in range(m-1):
    t1=t1+'#'
    t2=t2+'.'
    t3=t3+'.'
t1=t1+'#'
t2=t2+'#'
for i in range(n):
    if i%2==0:
        print(t1)
    elif i%4==1:
        print(t2)
    else:
        print(t3)