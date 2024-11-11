def sumDigits(n):
    sum = 0
    while n:
        sum += n%10
        n/=10
    return sum

t = int(input())

while t:
    if(t==0): break
    t-=1
    n = int(input())
    if n % 2050 != 0:
        print(-1)
    else:
        print(sumDigits(n//2050))