for _ in range(int(input())):
    n=int(input())
    x=input()
    a=""
    b=""
    for i in range(n):
        if(x[i]=='1'):
            a+="1"+"0"*(n-i-1)
            b+="0"*(n-i-1)+x[i+1:]
            break
        else:
            a+=str(int(x[i])//2)
            b+=str(int(x[i])//2)
    print(a)
    print(b)