a = []
for i in range(1,2000):
    if i%3 == 0 or (str(i))[-1] == '3': continue
    a.append(i)
t = int(input())
for i in range(t):
    n = int(input())
    print(a[n])