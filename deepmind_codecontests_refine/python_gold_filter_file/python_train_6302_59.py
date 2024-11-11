n=int(input())
if n<10:
    print(n)
elif n<190:
    n-=9
    m=9+(n-1)//2+1
    if n%2:
        print(m//10)
    else:
        print(m%10)
else:
    n-=189
    m=99+(n-1)//3+1
    if n%3==0:
        print(m%10)
    elif n%3==1:
        print(m//100)
    else:
        print((m//10)%10)
