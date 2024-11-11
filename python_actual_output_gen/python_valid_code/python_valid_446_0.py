for u in range(int(input())):
    n,k=input().split()
    n=int(n)
    s=input()
    c=0
    l=len(set(s))
    if(l==1 and s[0]==k):
        print(0)
    elif(s[-1]==k):
        print(1)
        print(n)
    else:
        f=0
        for i in range(n-1,n//2,-1):
            if(s[i]==k):
                f=i+1
                break
        if(f==0):
            print(2)
            print(n-1,n)
        else:
            print(1)
            print(f)
