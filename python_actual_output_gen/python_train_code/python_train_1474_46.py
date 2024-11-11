A,B,K=map(int,input().split())
y=[]
for i in range(1,min(A,B)+1):
    if A%i==0 and B%i==0:
        y.append(i)
print(y[K-1])