n = int(input())
 
arr = sum([int(x) for x in input().split()])
c = 0
for x in range(1,6):
    if (arr +x)%(n+1) == 0:
        c+=1
print(c)