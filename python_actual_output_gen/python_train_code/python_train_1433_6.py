h = int(input())

n = 0
while 2**n < h:
    n += 1

print(2**n-1)