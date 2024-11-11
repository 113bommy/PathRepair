N = int(input())

prime = []

for i in range(10,1145148101919+1):
    a = True
    for g in range(2, i-1):
        if i%g == 0:
            a = False
            break
    if a:
        if i%5==1:
            prime.append(i)
    if len(prime)==55:
        break
    
print(*prime[:N])