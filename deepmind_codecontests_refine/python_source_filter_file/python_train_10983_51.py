s = input()
m = len(s)
sum1 = 0
sum2 = 0

for i in range(m):
    if (s[i] >= '96' ):
        sum1 += 1
    else: sum2 += 1

s = str(s)
if (sum1 >= sum2):
    print(s.lower())

else:
    print(s.upper())