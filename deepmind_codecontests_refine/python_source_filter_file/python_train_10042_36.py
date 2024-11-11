# Author: SaykaT
# Problem: 47A
# Time Created: July 21(Tuesday) 2020 || 04:24:31

#>-------------------------<#
from math import sqrt


# Helper Functions. -> Don't cluster your code.

# IO Functions. -> Input output
def io():
    n = int(input())
    return n

# Main functions. -> Write the main solution here
def solve():
    n = io()
    a = float(1)
    b = float(1)
    c = -float(n * 2)

    d = (b ** 2) - (4 * a * c)
    sol1 = (-b + sqrt(d)) / (2 * a)
    sol2 = (-b - sqrt(d)) / (2 * a)
    if n == 1:
        print('Yes')
    elif sol1 > 1:
        if float(int(sol1)**2) == ((sol1 ** 2)):
            print('Yes')
        else:
            print('NO')
    elif sol2 > 1:
        if sol2 == ((sol2 ** 2) ** 0.5):
            print('Yes')
        else:
            print('NO')
    else:
        print('NO')

# Multiple test cases. -> When you have T test cases.
solve()
    
