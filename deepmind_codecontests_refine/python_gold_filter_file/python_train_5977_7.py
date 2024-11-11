n=int(input())
A=list(map(int,input().split()))
def gcd(x,y):
    while y:
        x,y=y,x%y
    return x
g=0
for a in A:
    g=gcd(g,a)
u=max(A)//g-n
if u%2==0:
    print("Bob")
else:
    print("Alice")