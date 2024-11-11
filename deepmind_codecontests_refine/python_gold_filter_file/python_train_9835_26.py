#code

a,b = map(int,input().split())

l = [ list(map(int,input().split())) for i in range(a) ]
    
sum = 0    
time = 1
    
for i in range(a):
    x = int((l[i][0]-time)/b)
    time = time + x*b 
    sum = sum + (l[i][1] - time+1)
    time = l[i][1] +1

print(sum)

