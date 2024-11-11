a,b,c = [int(i) for i in input().split()]
A = 0
for i in range(a,b):
    if c%i == 0:
        A += 1
print(A)