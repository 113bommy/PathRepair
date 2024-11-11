n = int(input())
x = []
y = []
for i in range(n):
    a, b = map(int, input().split())
    x.append(a)
    y.append(b)
min = 10**5
max = 0
for i in range(n):
    if x[i] < min:
        min = x[i]
for j in range(n):
    if y[j] > max:
        max = y[j]
tf = False
for i in range(n):
    if  x[i] == min and y[i] == max:
        tf = True
        print(i + 1)
if tf == False:
    print('-1')
