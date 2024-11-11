n=int(input())
for i in range (n) :
    a,b,c,d,e=[int(i) for i in input().split()]
    s=0
    if a%b==0 :
        x=a//c
    else :
        x=a//c+1
    if b%d==0 :
        y=b//d
    else :
        y=b//d+1
    if x+y>e :
        print('-1')
    else :
        print (x,y)
