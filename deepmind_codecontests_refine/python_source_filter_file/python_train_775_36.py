y=list(map(int,input().split()))
n1=y[0]
n2=y[1]
k1=y[2]
k2=y[3]
if n1+k1 >n2+k2:
    print("First")
else:
    print("Second")