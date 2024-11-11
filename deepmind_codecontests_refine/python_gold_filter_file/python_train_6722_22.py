x = int(input())
xd=[]
for i in range(1, x+1):
    if (x%i == 0 and i <= x/i):
        xd.append([i, x//i])
    
xd.sort(key = lambda x:x[1]-x[0])
print(xd[0][0], xd[0][1]);