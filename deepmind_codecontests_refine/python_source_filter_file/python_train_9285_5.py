n = int(input())

a = input().split()
a = map(int,a)
a = list(a)



if n%2:
    half = ((n-1)/2)
    half = int(half)
    x = sum(a[:half])
    y = sum(a)-x
else:
    x = sum(a[:int((n/2))])
    y = sum(a)-x
    
length = x**2 + y**2


print(length)
    