
# Author: SaykaT
# Problem: 47B
# Time Created: July 23(Thursday) 2020 || 03:18:05

#>-------------------------<#

# Helper Functions. -> Don't cluster your code.

# IO Functions. -> Input output
def io():
    ls = []
    for _ in range(3):
        tmp = input()
        ls.append(tmp)
    return ls

# Main functions. -> Write the main solution here
def solve():
    ls = io()
    ans = ['1', '1', '1']
    another_ls = []
    for i in ls:
        if '<' in i:
            i = i[::-1]
            i = i.replace('<', '>')
        another_ls.append(i)

    if 'A>C' in another_ls and 'A>B' in another_ls and 'B>C' in another_ls:
        print('CBA')
    elif 'A>C' in another_ls and 'A>B' in another_ls and 'C>B' in another_ls:
        print('BCA')
    elif 'B>A' in another_ls and 'B>C' in another_ls and 'A>C' in another_ls:
        print('BAC')
    elif 'B>C' in another_ls and 'B>A' in another_ls and 'C>A' in another_ls:
        print('ACB')
    elif 'C>A' in another_ls and 'C>B' in another_ls and 'A>B' in another_ls:
        print('BAC')
    elif 'C>A' in another_ls and 'C>B' in another_ls and 'B>A' in another_ls:
        print('ABC')
    else:
        print('Impossible')


# Multiple test cases. -> When you have T test cases.
solve()
    
