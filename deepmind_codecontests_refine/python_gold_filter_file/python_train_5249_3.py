n, b, p = map(int, input().split())
meals = list(map(int, input().split()))
x = meals.count(1)
y = meals.count(2)

b -= x
if b >= 0:
    p += b
p -= y
count = 0
if b < 0:
    count+=b
if p < 0:
    count+=p
print(abs(count))
    