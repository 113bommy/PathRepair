n = int(input())

def is_prime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True
    
num = 11
tmp = 0
while 1:
    if is_prime(num):
        print(num, end = " ")
        tmp += 1
    num += 10
    if n == tmp:
        exit()