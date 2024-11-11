inp = input().split()
n = int(inp[0])
x = int(inp[1])
y = int(inp[2])
a = input().split('1')

zeros = 0
for z in a:
    if len(z) > 0:
        zeros += 1
        
print(min(zeros *y,y + (zeros-1)*x))
    