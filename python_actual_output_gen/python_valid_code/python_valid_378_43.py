n=int(input())
a=10**12
for i in range(1,int(n**0.5)):
    if n%i==0:
        a=min(a,i+n//i-2)
print(a)