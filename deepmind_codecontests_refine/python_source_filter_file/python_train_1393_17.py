sum = 0
c=0
n = int(input())
a = []
a = input().split()
for i in range(n):
    sum += int(a[i])
for x in range(1,6):
    if (8 + x)%(n+1) ==1:
        pass
    else:
        c+=1
print(c)