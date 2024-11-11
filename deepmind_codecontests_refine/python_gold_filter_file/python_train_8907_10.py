import math

def main():
    (a,b) = list(map(int,input().split()))
    if b > a:
        a, b = b, a
    while b != 0:
        b, a = a%b, b
    divisors = []
    root = math.floor(math.sqrt(a))
    for divisor in range(1,root):
        if a % divisor == 0:
            divisors.append(divisor)
            divisors.append(a//divisor)
    if a % root == 0:
        divisors.append(root)
        if root**2 != a:
            divisors.append(a//root)
    divisors.sort()
    divisors = [0] + divisors
    length = len(divisors)
    n = int(input())
    for _ in range(n):
        (low,high) = list(map(int, input().split()))
        left = 1
        right = length
        best = 0
        while left < right:
            middle = (left+right)//2
            if divisors[middle] > high:
                right = middle
            else:
                best = divisors[middle]
                left = middle + 1
        if best < low:
            print("-1")
        else:
            print(best)        
    
main()
