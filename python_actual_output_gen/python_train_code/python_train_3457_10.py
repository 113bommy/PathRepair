n = int(input())

def primes(n):
    if n == 1:
        return False
    if n == 2 or n == 3:
        return True
    if n%6 == 5 or n%6 == 1:
        check = True
        for i in range(2,int((n+1)/2)):
            if n%i == 0:
                check = False
                break
        if check is True:
            return True
        else:
            return False
    return False

number = 0
i = 2 
while i < n:
    count = 0
    for j in range(2,i):
        if i%j == 0:
            if primes(j) == True:
                count += 1
                if count > 2:
                    break
    if count == 2:
        number += 1
    i+=1

print(number+1)
    

