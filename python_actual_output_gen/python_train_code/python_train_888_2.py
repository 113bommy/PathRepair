def big_f(n):
    f = 1
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            f= n//i
        break
    return f
z = int(input())
total = z
while z>1:
    z = big_f(z)
    total += z
print(total)