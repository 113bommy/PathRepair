"""for _ in range(int(input())):
    n,m=map(int,input().split())
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    f=0
    for i in range(n):
        if l1[i] in l2:
            f=1
            ans=l1[i]
            break
    if(f==0):
        print("NO")
    else:
        print("YES")
        print(1, ans)"""
"""for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    x=l.count(1)
    if(x==0):
        print("First")
    else:
        if(x==n):
            if(n%2==0):
                print("Second")
            else:
                print("First")
        else:
            c=0
            for i in range(n):
                if(l[i]==1):
                    c+=1
                else:
                    break
            if(c%2==0):
                print("First")
            else:
                print("Second")"""
for _ in range(int(input())):
    n=int(input())
    la=str(input())
    lb=str(input())
    ans=n
    l=[]
    a=list(la)
    b=list(lb)
    left=0
    right=n-1
    for i in range(n-1,-1,-1):
        temp=n-i+1
        if(temp%2==0):
            if(a[left]==b[i]):
                l.append(1)
                left+=1
            l.append(i+1)
        else:
            if(a[right]!=b[i]):
                l.append(1)
                right-=1
            l.append(i+1)


    print(len(l),end=" ")
    for i in range(len(l)):
        print(l[i],end=" ")
    print()
