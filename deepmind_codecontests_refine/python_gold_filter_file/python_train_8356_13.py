a=int(input())
for x in range(a):
    n=int(input())
    if n==1 or n==2 or n ==4:
        print(-1)
        continue
    b=n//3
    if  n%3==1:
        print(b-2,0,1)
    elif n%3==0:
         print(b,0,0)
    else:
        print(b-1,1,0)
