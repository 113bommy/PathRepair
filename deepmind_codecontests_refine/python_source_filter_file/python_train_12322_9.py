import math

def solve(n):
    upper = int(n**0.5)+1
    lower = 10**(math.log10(n**0.5//1)//1)
    if n**0.5 - 10**(math.log10(n**0.5//1)//1) >= 10000:
        lower = n**0.5-10000
    for i in range(int(lower),upper):
        if i**2 + s(i)*i == n:
            return(i)
    return(-1)

    
def s(x):
    output = 0
    while x != 0:
        output += x%10
        x //=10
    return output


n = int(input())
print(solve(n))
