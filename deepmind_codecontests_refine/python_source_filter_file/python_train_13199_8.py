n=int(input())
m=n
for i in range(1,int(n**.5)+1):
    if n%i==0:
        m=min(m, n//i+i)
print(m-2)
