# Author: SaykaT
# Problem: 66B
# Time Created: July 19(Sunday) 2020 || 10:56:36

#>-------------------------<#

# Helper Functions. -> Don't cluster your code.

# IO Functions. -> Input output
def io():
    n = int(input())
    ls = list(map(int, input().split()))
    return [n, ls]

# Main functions. -> Write the main solution here
def solve():
    n, ls = io()
    ans = 0
    rns = 0
    if n == 1:
        print(1)
    else:
        for i in range(n):

            rn = 1
            for j in range(i+1, n-1):
                if ls[j-1] >= ls[j]:
                    rn += 1
                else:
                    break
            for k in range(i-1, -1, -1):
                if ls[k+1] >= ls[k]:
                    rn += 1
                else:
                    break
            if rn > rns:
                rns = rn
                ans = i + 1
        print(rns)
            

# Multiple test cases. -> When you have T test cases.
solve()
