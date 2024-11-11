a=input()
for i in range(int(a)):
    b=int(input())
    c=list(map(int,input().split()))
    if(c[0]+c[1]<c[b-1]):
        print(1,2,b)
    else:
        print(-1)