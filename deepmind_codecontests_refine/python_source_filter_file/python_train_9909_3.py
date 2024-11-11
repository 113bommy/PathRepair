n=int(input())

d = int(input())

e= int (input())
a= (n%d)%(e*5)
b= (n%(e*5))%d
c= n%(d+e*5)


ans = n%d
n -= 5*e
while n>=0:
    ans= min(ans,n%d)
    n-= 5*3

print(min(min(a,b),ans))


