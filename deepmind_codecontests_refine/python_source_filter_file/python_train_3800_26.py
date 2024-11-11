import math

n, x = map(int, input().split(" "))

def divs(n, x):
    div = []
    for i in range(1, n+1):
        if x%i == 0 and x/i <= n:
            div.append(i)
    return div

divisors = [i for i in divs(n, x)]

print(divisors)
