n = int(input())
d = int(input())
e = int(input()) * 5

m = 100

euro = 0
while euro <= n:
    m = min(m, (n-euro) - ((n-euro)//d)*d)
    euro += e
print(m)
