N=int(input())
a=0

for i in range(1,int(N**(1/2))):
    b=N//i
    if N%i==0:
        a=i+b-2
print(int(a))