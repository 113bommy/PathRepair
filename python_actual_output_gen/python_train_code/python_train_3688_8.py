for _ in range(int(input())):
    n,x=map(int,input().split())
    l=list(map(int,input().split()))
    oc=len(list(filter(lambda x:(x%2!=0),l)))
    ec=len(list(filter(lambda x:(x%2==0),l)))
    if oc<x:
        if oc>=1 and oc%2!=0 and x==n:
            print("yes")
        elif x<n and oc>=1:
            print("yes")
            
        else:
            print("no")
    if oc==x:
        if ec>=1 and oc %2==0:
            print('yes')
        elif oc%2!=0:
            print('yes')
        else:
            print('no')
    if oc>x:
        if oc%2!=0:
            print('yes')
        elif ec>=1:
            print('yes')
        else:
            print('no')
        
    