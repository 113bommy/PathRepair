n,p=map(int,input().split())
A=[i%2 for i in map(int,input().split())]
A0=A.count(0)
A1=A.count(1)
if p==1 and A1==0:
    print(0)
elif p==1 and A1==0:
    print(2**A0)
else:
    print((2**A0)*(2**A1)//2)
