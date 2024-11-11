
n = int(input())

str = input()

array = [int(x) for x in str.split(' ')]

fSum = [0]*n

fSum[0]=array[0]

for x in range(n-1):
    fSum[x+1]=fSum[x]+array[x+1]
    
bSum = [0]*n
bSum[n-1]=array[n-1]

i=n-2
while(i>=0):
    bSum[i]=bSum[i+1]+array[i]
    i-=1
    

largeVal = 0

j=n-1

for x in range(n):
    
    fVal = fSum[x]
    
    while(fVal>bSum[j]):
        j-=1
        
    if x>j:
        break
        
        
    if fVal == bSum[j]:
        largeVal = fVal
    
   
    

print(largeVal)
    

