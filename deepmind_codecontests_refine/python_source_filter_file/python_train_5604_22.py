def is_prime(n):
    if n%2==0:return False
    for i in range(3,int(n**0.5),2):
        if n%i==0:return False
    return True
print(*[i for i in range(6,55556,5) if is_prime(i)][:int(input())])