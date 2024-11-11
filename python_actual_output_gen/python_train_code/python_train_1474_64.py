a,b,k = map(int,input().split())
A=[]

for i in range(1,101):
    if a%i == 0 and b%i==0:
        A.append(i)
print(A[k-1])