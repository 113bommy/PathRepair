def gcd(a,b):
    while b:a,b=b,a%b
    return a

def lcm(a,b):
    return a/gcd(a,b)*b

input()
a=list(map(int,input().split()))
b=1
for i in a:
    b=lcm(b,i)
print(b)