M=int(input())
D,C=zip(*[map(int,input().split()) for i in range(M)])
X=[d*c for d,c in zip(D,C)]
print(sum(C)-1+sum(X)//10)