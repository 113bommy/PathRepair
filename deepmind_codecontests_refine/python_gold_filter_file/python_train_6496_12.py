x = input().split()
a = int(x[0])
b = int(x[1])
l = [int(i) for i in input().split()]
l.insert(0,1)
t = 0
for i in range(b):
    if l[i+1] < l[i]:
        t += (a-l[i])+l[i+1]
    elif l[i+1] == l[i]:
        t += 0
    elif l[i] < l[i+1] <= a:
        t += l[i+1] - l[i]
print(t)

