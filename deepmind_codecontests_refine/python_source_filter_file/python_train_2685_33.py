from math import gcd
def lcm(a,b):
    return (a*b)//gcd(a,b)
n,m = map(int,input().split())
a = list(map(int,input().split()))
ans = 1
for i in a:
    ans = lcm(ans,i)
for i in a:
    if (ans//i) % 2 == 0:
        print(0)
        exit()
print(((m//(ans//2))+1)//2)