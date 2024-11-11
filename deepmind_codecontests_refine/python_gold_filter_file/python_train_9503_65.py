n = int(input())

fact = 1

for x in range(1,n+1):
    fact *= x

print(int(fact/(n*(n/2))))