
# Author: SaykaT
# Problem: 16B
# Time Created: July 21(Tuesday) 2020 || 12:16:23

#>-------------------------<#

# Helper Functions. -> Don't cluster your code.

# IO Functions. -> Input output
def io():
    n, m = map(int, input().split())
    containers = []
    for _ in range(m):
        a, b = map(int, input().split())
        containers.append([a, b])
    containers.sort(key=lambda x:x[1], reverse=True)
    return [n, m, containers]

# Main functions. -> Write the main solution here
def solve():
    n, m, containers = io()
    i = 0
    matches = 0
    while n != 0 and i < m:
        if n > containers[i][0]:
            matches += containers[i][0] * containers[i][1]
            n -= containers[i][0]
        else:
            matches += n * containers[i][1]
            
            n = 0
        i +=1
    print(matches)

# Multiple test cases. -> When you have T test cases.
solve()
    
