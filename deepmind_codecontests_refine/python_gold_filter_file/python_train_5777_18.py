n=input('');
n=int(n);
if n==3:
    print("2\n1 3")
elif n==4:
    print("4\n2 4 1 3")
elif n==2:
    print("1\n1")
else:
    print(n)
    print("1",end=''),
    for i in range(3,n+1,2):
        print(' ',end=''),
        print(i,end='')
    for i in range(2,n+1,2):
        print(' ',end=''),
        print(i,end=''),
    print("")

        
