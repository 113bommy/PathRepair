for _ in range(int(input())):
    n=int(input())
    l=[int(x) for x in input().split()]
    f=0
    for i in range(n-2):
        temp=l[i]+l[i+1]
        if l[i+2]>temp:
            print(i+1,i+2,i+3)
            f=1
            break
    if f==0:
        print(-1)