def solve(n,t):
    number = 10**(n-1)
    while (number % t != 0):
        number += 1
        if number >= 10**n - 1:
            number = -1
            break
    print(number)

s = input().split(' ')
n = int(s[0])
t = int(s[1])

solve(n,t)