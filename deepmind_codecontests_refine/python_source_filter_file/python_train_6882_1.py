def getSum(n): 
    sum = 0
    while (n != 0): 
        sum = sum + int(n % 10) 
        n = int(n/10) 
    return sum

n = int(input())
if n<=9:
    print(n)
else:
    x=0
    while x*10+9<=n:
        x+=x*10+9
    print(getSum(x)+getSum(n-x))