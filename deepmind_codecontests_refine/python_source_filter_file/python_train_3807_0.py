n=int(input())
if n==2 or n==3:
    exit(print(1))
elif n%2==0:
    exit(print(2))
for i in range(n,n-3,-1):
    if i!=n-1:
        for j in range(2,int(i**0.5)+1):
            if i%j==0:
                break
            elif j==int(n**0.5):
                if i==n:
                    exit(print(1))
                else:
                    exit(print(2))
exit(print(3))
                    