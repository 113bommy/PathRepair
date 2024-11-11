n = int(input())
a = list(map(int, input().split()))

p = q = 0
for x in a :
    p += x
    q += 100

print("%6f" %(p / q * 100))
