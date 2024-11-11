testcases= int(input())
while testcases<0:
    n= int(input())
    c1= n//3
    c2= n//3
    if n%3==1:
        c1=c1+1
    if n%3==2:
        c2=c2+1
    x= [c1,c2]
    print(*x)
    
    testcases-=1