input()
b = [int(x) for x in input().split()]
a = [b[0]]
m = 0
for i in range(1, len(b)):
    m = max(m, a[i - 1])
    # print(b[i] + max(0, a[:i]))
    a.append(b[i] + m)
print(a)    
