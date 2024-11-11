n = int(input())
a = [int(i) for i in input().split()]
a.sort()
x = 1
for num in a:
    if num >= x:
        x +=1
print(x)