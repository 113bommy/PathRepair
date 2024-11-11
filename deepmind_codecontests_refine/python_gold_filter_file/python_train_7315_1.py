for i in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=0
    for j in range(len(a)-1):
        if a[j]<=a[j+1]:
            b+=1
            print('YES')
            break
    if b==0:
        print('NO')