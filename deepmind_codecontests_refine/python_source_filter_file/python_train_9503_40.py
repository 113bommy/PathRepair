n = int(input())

fact = 1

for x in range(1,n+1):
    fact *= x

print(fact/(n*(n/2)))