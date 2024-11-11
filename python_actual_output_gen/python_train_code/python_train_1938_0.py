n,a,b,c = map(int, input().strip().split(' '))
#n=int(input())
#lst = list(map(str, input().strip().split(' ')))
if n%4==0:
    print(0)
else:
    k=4-(n%4)
    if k==3:
        print(min(3*a,2*b,c,a+b))
    elif k==2:
        print(min(2*a,b,2*c))
    elif k==1:
        print(min(a,b+c,3*c))
   
    
    
       