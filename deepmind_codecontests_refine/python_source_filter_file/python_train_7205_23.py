for i in range(int(input())):
    a=list(input().split())
    a=[int(i) for i in a]
    if sum(a)%3==0 and a[3]>=(2*max(a[:3])-sum(a[:3])):
        print("YES")
    else:
        print('NO')