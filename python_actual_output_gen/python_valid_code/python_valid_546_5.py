for i in range(int(input())):
    a,b=map(int,input().split())
    l=abs(a-b)//2
    r=a+b-l
    j=1
    if a+b%2==0:
        j=2
    a = list(range(l, r + 1, j))
 
    print(len(a))
    print(*a)