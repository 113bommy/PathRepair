
testcase=int(input())

for test in range(0,testcase):
    n=int(input())
    a=list(map(int,input().split()))

    b=list()
    if n%2==0:
        for i in range(0,n,2):
            b.append(-1*a[i+1])
            b.append(a[i])
    else:
        for i in range(0,n-3,2):
            b.append(-1*a[i+1])
            b.append(a[i])
        if a[-3]+a[-2]!=0:
            b.append(-1*a[-1])
            b.append(-1*a[-1])
            b.append(a[-2]+a[-3])
        elif a[-2]+a[-1]!=0:
            b.append(a[-1]+a[-2])
            b.append(-1*a[-3])
            b.append(-1*a[-3])
        elif a[-1]+a[-3]!=0:
            b.append(a[-2])
            b.append(a[-1]+a[-3])
            b.append(a[-2])
    print(*b)