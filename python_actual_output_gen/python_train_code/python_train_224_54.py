a,b,c=map(int,input().split())
count = 0
for x in range(a,b):
    if (c%x==0):count += 1
print(count)