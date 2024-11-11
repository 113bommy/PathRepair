import copy;
import math;
n = int(input());
arr = [];
for i in range(n):
    arr.append(float(input()));
s=0;
array = copy.deepcopy(arr)
for i in range(n):
    array[i] = math.floor(array[i])
    s+=array[i];
ptr=0;
#print(array)
while(s!=0):
    if(arr[ptr]!=0):
        array[ptr]+=1;
        s+=1;
    ptr+=1;
print(*array)
    
        
        
        
