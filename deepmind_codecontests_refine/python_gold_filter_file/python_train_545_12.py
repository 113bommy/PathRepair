n=int(input())
num=list(map(int,input().split()))
print("1 1")
x=[]
if n!=1:
    print(-num[0])
    num[0]=num[0]-num[0]
    for i in range(1,n):
        x.append((num[i]%n)*(n-1))
        num[i]+=x[i-1]
        num[i]*=-1
    print("2 {}".format(n))
    for c in x:
        print(c,end=' ')
    print("\n1 {}".format(n))
    for d in num:
        print(d,end=' ')
else:
    print("0\n1 1\n0\n1 1\n{}".format(-1*num[0]))