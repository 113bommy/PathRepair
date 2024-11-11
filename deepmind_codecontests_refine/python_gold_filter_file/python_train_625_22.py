a,b,c = map(int, input().split())
num = 0
for x in range(a,b+1):
    if c%x == 0:
        num+=1
print(num)
