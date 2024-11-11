
# Author: SaykaT
# Problem: 1373B
# Time Created: July 16(Thursday) 2020 || 11:19:55

#>-------------------------<#

# Helper Functions. -> Don't cluster your code.

# IO Functions. -> Input output
def io():
    s = input()
    return s

# Main functions. -> Write the main solution here
def solve():
    s = io()
    move = 0
    while True:
        if '01' in s:
            move += 1
            s = s.replace('01', '')
        elif '10' in s:
            move += 1
            s = s.replace('10', '')
        else:
            break
    if move % 2 == 0:
        print('NET')
    else:
        print('DA')

# Multiple test cases. -> When you have T test cases.
T = int(input())
for _ in range(T):
    solve()
    
