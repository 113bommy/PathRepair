def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    return digits[::-1]

def gcd(a,b):
     
    # Everything divides 0
    if (a == 0):
        return b
    if (b == 0):
        return a
 
    # base case
    if (a == b):
        return a
 
    # a is greater
    if (a > b):
        return gcd(a-b, b)
    return gcd(a, b-a)    

def solve(x):
    tot = 0
    count = 0
    for i in range(2,x):
        v = numberToBase(x,i)
        tot += sum(v)
        count += 1
    n = gcd(tot,count)
    if n != tot:
        tot = tot//n
        count = count//n

    return f'{tot}/{count}'

   
    


def main():
    # n,k = list(map(int,input().split(" ")))
    x = int(input())
    # arr = []
    # for _ in range(n):
    #     arr.append(list(map(int,input().split(" "))))
    print(solve(x))

main()