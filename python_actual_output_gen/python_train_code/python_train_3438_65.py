X=int(input())
n=1
for b in range(2,int(X**0.5)):
    p=2
    while b**p<=X:
        n=max(n,b**p)
        b+=1
print(n)