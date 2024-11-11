n = int(input())
l = []
for i in range(n):
    y = input().split("x")
    l.append(y)
    
x = 0
for j in range(len(l)):
    if "++" in l[j]:
        x += 1
    elif "--" in l[j]:
        x = x - 1

print(x)

