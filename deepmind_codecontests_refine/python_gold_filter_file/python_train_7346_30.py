n = int(input())
i = 0
t = n
while (t > i):
    i += 1
    t -= i
print(str(i))
for x in range(1, i):
    print(str(x)+" ", end="")
print(str(t + i))
