import math

def odddivisors(n):
    return [ i for i in range(3, n+1) if i % 2 == 1 and n % i == 0 ]

def solve(n):

    sol = [None] * (n+1)
    
    for i in range(1, n+1):

        if i == 1:
            sol[i] == 'B'

        for j in [i-1] + [i//d for d in odddivisors(i)]:
            if sol[j] == 'B':
                sol[i] = 'A'
                break
        else:
            sol[i] = 'B'
                
        print(f"{i}: {sol[i]}  {j if sol[i]=='A' else ''}")


    print(f"even A: {[i for i in range(1, n+1) if i % 2 == 0 and sol[i]=='A']}")
    print("")
    print(f"even B: {[i for i in range(1, n+1) if i % 2 == 0 and sol[i]=='B']}")
    print("")
    print(f"odd A:  {[i for i in range(1, n+1) if i % 2 == 1 and sol[i]=='A']}")
    print("")
    print(f"odd B:  {[i for i in range(1, n+1) if i % 2 == 1 and sol[i]=='B']}")
    print("")


def power_of_2(n):
    while n >= 1:
        if n % 2 == 1:
            return False
        n //= 2
    return True
        
def prime(n):

    if n <= 3:
        return True
    
    if n % 2 == 0 or n % 3 == 0:
        return False

    lim = int(math.sqrt(n))+1
    for i in range(5, lim+1, 6):
        if n % i == 0 or n % (i+2) == 0:
            return False
    return True


def solve2(n):
    if n == 1:
        return False

    if n % 2 == 1:
        return True

    if n == 2:
        return True

    if power_of_2(n):
        return False

    if prime(n // 2):
        return False

    return True


t = int(input().strip())

for _ in range(t):

    n = int(input().strip())

    print('Ashishgup' if solve2(n) else 'FastestFinger')
