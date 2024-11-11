def gcd(a,b):
    if(b==0):
        return a
    return gcd(b,a%b)
n=int(input())
t=n//2
for i in range(t+1,n+1):
    if(gcd(i,n-i)==1):
        print(i,n-i)
        break
