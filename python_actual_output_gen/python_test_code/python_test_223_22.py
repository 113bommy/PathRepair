n, v = input().split()
n = int(n)
v = int(v)
if(n == 0):
    print(0)
    exit()
alpha = n - v - 1
sum = v
i = 2
while(alpha > 0):
    sum = sum + i
    i = i + 1
    alpha = alpha - 1
print(sum)