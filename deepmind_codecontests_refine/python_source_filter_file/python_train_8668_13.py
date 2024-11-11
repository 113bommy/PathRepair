t=int(input())
for q in range(0,t):
    s=input()
    lst=list(map(int,s.split()))
    x=int(lst[0])
    y=int(lst[1])
    k=int(lst[2])
    ans=0
    balance=0
    if (k*y+k-1)%(x-1)!=0:
        balance=1
    ans=int((k*y+k-1)/(x-1)+balance+k)
    print(int(ans))