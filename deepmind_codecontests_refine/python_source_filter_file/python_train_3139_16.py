#python 3.5.2
import math
import sys

H,n = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]

#print(H,n)
#print(d)
max_loss=0
total_loss = 0
for i in range(len(d)):
    total_loss += d[i]
    max_loss = min(max_loss, total_loss)  
    if(abs(total_loss) >= H):
        print(i+1)
        sys.exit()

if(total_loss >=0):
        print(-1)
        sys.exit()

max_loss = abs(max_loss)
total_loss = abs(total_loss)

#print(max_loss, total_loss)
x = math.ceil((H - max_loss)/total_loss)
#print(x)


energy_left = H-(x*total_loss)
#print("energy_left", energy_left)

i=0
count=0
while(i<len(d) and energy_left>0):
    count+=1
    energy_left += d[i]
    i+=1

count += (x*n)
print(count)    
  