n=int(input())
if(n>=1 and n<=9):
    print(n)
elif(n>=10 and n<=190):
    a=n-10
    if(a%2==0):
        print(str(n-(a//2))[0])
    else:
        print(str(n-(a//2+1))[1])
elif(n>=191 and n<=999):
    a=n-191
    print(str(100+(a//3))[a%3])
elif(n==1000):
    print('3')
        
