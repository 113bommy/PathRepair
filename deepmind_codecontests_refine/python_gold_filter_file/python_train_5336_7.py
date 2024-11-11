for _ in range(int(input())):
    n=int(input())
    flag=True
    if n%2==0:
        print(n//2, n//2)
    else:
        i=2
        while i*i<=n:
            if n%i==0:
                print(n//i,n-n//i)
                flag=False
                break
            i+=1
        if (flag):
            print(1,n-1)
       