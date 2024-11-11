n = int(input())
s = 0
p = 1
for i in range(5):
    p = p * (n-i)
s = s + p / 120
p = 1
for i in range(6):
    p = p * (n-i)
s = s + p / 720
p = 1
for i in range(7):
    p = p * (n-i)
s = s + p / 5040
print (s)