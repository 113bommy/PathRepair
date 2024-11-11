n=int(input())
i=2
while i<=n**(1/2):
    if n%((i)**2)==0:
        n=n/(i)
        i=2
    i+=1
print(int(n))