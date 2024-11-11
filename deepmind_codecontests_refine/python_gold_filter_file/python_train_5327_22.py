for i in range(int(input())):
    n,s,t=map(int,input().split())
    if n==s and n==t:
        print(1)
    else:
        print(max(n-s,n-t)+1)
