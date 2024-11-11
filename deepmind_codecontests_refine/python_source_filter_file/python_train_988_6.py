n, a = map(int, input().split())
s1 = input().split()
s1 = [0]*(40 - n) + s1
m, b = map(int, input().split())
s2 = input().split()
s2 = [0]*(40 - m) + s2
sum1 = 0
sum2 = 0
for i in range(40):
    sum1 += int(s1[i]) * a ** (40 - i - 1)
    sum2 += int(s2[i]) * b ** (40 - i - 1)
if sum1 > sum2:
    print('>')
elif sum2 == sum1:
    print('=')
else:
    print('<')
print(sum1)
print(sum2)