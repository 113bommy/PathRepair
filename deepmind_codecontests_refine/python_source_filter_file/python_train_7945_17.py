n = int(input())
q = n
z = [] 
while n:
    a,b = [int(i) for i in input().split()]
    z.append([a,b])
    n-=1
c = 0
print(z)
for i in range(q):
    r,l,u,low = 0,0,0,0
    for j in range(q):
        x = z[i][0]
        y = z[i][1]
        if i==j:
            pass
        else:
            if x < z[j][0] and y == z[j][1]:
                r+=1
            if x > z[j][0] and y == z[j][1]:
                l+=1
            if x == z[j][0] and y < z[j][1]:
                u+=1
            if x == z[j][0] and y > z[j][1]:
                low+=1


    if(r>=1 and l>=1 and low>=1 and u>=1):
        c+=1
print(c)
                
            
