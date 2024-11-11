p=int(input())
while(p):
    l=list(map(int,input().split()))
    print(min(2,l[0])*l[1])
    p=p-1