
x = [int(i) for i in input().split()]

def gcd(a,b):
    while b > 0:
        a, b = b, a % b
    return a
    
def lcm(a, b):
    return a * b / gcd(a, b)
t=x[2]//lcm(x[0],x[1])
print(int(t))