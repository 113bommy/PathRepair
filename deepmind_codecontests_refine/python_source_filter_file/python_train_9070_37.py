from math import fabs

w1 = input().split()
h1 = int(w1[1])
w2 = int(w1[2])
h2 = int(w1[3])
w1 = int(w1[0])

sum = h1 + h2 + 2
sum *= 2
sum += w1 + w2
sum += fabs(w1 - w2)
print(sum)