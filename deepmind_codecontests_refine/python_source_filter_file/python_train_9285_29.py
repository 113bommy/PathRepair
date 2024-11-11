x = int(input())
y = list(map(int, input().split()))

a = int(x/2)
b = 0
c = 0

for i in range(a, x):
    b+=y[i]
for i in range(a):
    c+=y[i]
print(b**2+c**2)