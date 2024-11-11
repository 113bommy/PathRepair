r1c1,r1c2,r1c3 = map(int, input().split())
r2c1,r2c2,r2c3 = map(int, input().split())
r3c1,r3c2,r3c3 = map(int, input().split())
for i in range(10**5+1):
    if i+r1c2+r1c3 == i+r2c1+r3c1:
        sum = i+r1c2+r1c3
        b = sum - (r1c2+r3c2)
        if b+r2c1+r2c3 == b+r1c3+r3c1:
            if sum-(i+b) ==sum-(r1c3+r2c3):
                r1c1 = i
                r2c2 = b
                r3c3 = sum-(i+b)
                break
print(r1c1,r1c2,r1c3)
print(r2c1,r2c2,r2c3)
print(r3c1,r3c2,r3c3)
