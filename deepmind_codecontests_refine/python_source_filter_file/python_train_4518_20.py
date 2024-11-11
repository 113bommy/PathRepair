a,b,n=list(map(int,input().split()))
if a==0 and b!=0 or n==0 and a!=b or a!=0 and b/a<0 and n%2==0:
    print('No solution')
elif n==0 or a==0 and b==0:
    print(1)
else:
    z=0
    for i in range(-abs(round(b/a)),abs(round(b/a))):
        if a*i**n==b:
            z=1
            print(i)
            break
    else:
        print('No solution')