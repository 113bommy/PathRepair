n=int(input())
if(n>=1 and n<=9):
    print(n)
elif(n>=10 and n<=189):
    a=n-10
    if(a%2==0):
        print(str(n-(a//2))[0])
    else:
        print(str(n-(a//2+1))[1])
elif(n>=190 and n<=999):
    a=n-190
    print(str(100+(a//3))[a%3])
elif(n==1000):
    print('3')
        
