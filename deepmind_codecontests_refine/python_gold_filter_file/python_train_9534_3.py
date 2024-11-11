import sys

def getSum(n):
    sum = 0
    while n:
        sum += n % 10
        n //= 10
    return sum
    
def getMax(n):
    
    res = n
    b = 1
    
    while n:
        cur = (n - 1) * b + (b - 1)
        
        if (getSum(cur) > getSum(res)) or (getSum(cur) > getSum(res) and cur > res):
            res = cur
        b *= 10
        n //= 10
    return res

def main():
    n = int(sys.stdin.readline().strip())
    print(getMax(n))
main()