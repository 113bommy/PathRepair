def digitsum(n):
    d = list(str(n))
    wa = 0

    for di in d:
        wa += int(di)
    
    return wa

a = int(input())
for n in range(a, 1004):
    if digitsum(n) % 4 == 0:
        print(n)
        break