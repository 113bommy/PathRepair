from fractions import Fraction

chance = 1
y, k = map(int, input().split())
val = max(y,k)
chance += (6-val)
prob = chance / 6
temp = str(Fraction(prob).limit_denominator(10))
if temp == 1:
    temp = '1/1'
elif temp == 0:
    temp = '0/1'
else:
    temp = temp
print(temp)
