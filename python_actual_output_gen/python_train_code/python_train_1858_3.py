def GCD(x, y):
    while y != 0:
        remainder = x % y
        x = y
        y = remainder
    return x

def LCM(x, y):
    return x * y // GCD(x, y)

n, m = map(int, input().split())
b, *boys = list(map(int, input().split()))
g, *girls = list(map(int, input().split()))
isHappy = [False] * (n + m)
for boy in boys: isHappy[boy] = True
for girl in girls: isHappy[girl + n] = True

for i in range(LCM(m , n)):
    if isHappy[i % n] or isHappy[i % m + n]: isHappy[i % n] = isHappy[i % m + n] = True

flag = True
for check in isHappy: 
    if not check: 
        flag = False
        break
print("Yes" if flag else "No")