def sum_of_digits(a):
    sum=0
    while a!=0:
        sum += a%10
        a = a//10
    return sum
    
a = int(input())
n = a
r = sum_of_digits(n)%4
while r!=0:
    n += 4-r
    r = sum_of_digits(n)%4
    
print(n)

