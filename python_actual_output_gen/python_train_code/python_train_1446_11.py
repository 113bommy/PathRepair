for _ in range(int(input())):
    n=int(input())
    s=input()
    first,last=0,0
    for i in range(n//2+1):
        if s[i]=='1':
            first=n-i
            break
    for i in range(n-1,n//2,-1):
        if s[i]=='1':
            last=i+1
            break
    case1=max(last,first)*2
    
    print(case1)
            