N = int(input())
def prime(n):
    flag = False
    for i in range(2,int(n**0.5)+1):
        if n%i == 0:
            return False
            break
    return True
    

L = []
for i in range(2,55556):
    if prime(i) and i%5 == 1:
        L.append(i)
print(*L[:N])