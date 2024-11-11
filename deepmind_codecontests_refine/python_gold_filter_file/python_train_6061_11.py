for i in range(int(input())):
    n=int(input())
    if n%2==0:
        print (n//2*'1')
    else:
        print ('7'+(n-3)//2*'1')