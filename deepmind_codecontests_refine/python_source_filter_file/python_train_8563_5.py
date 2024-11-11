from fractions import gcd
def base(n,x):
    s=0
    while x//n!=0:
        s+=x%n
        x//=n
    s+=x%n
    return s
n=int(input())
nb=0
for i in range(2,n):
    nb+=base(i,n)
g=gcd(nb,n-2)
print(str(nb//2)+'/'+str((n-2)//g))