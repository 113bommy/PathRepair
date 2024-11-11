n,k=map(int,input().split())
t=list(map(int,input().split()))
def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a
ans=t[0]
for i in range(n):
    ans=gcd(ans,t[i])
if k%ans==0:
    if k<max(t):
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")