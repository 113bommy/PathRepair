n=int(input())
 
y=[int(i) for i in input().split()]
y.append(0)
 
t=0
totalone=y.count(1)
countone=0
 
for i in range(n):
    #print(i)
 
    if y[i] == 1 and y[i+1]==1:
        #print(i,'here1')
        t+=1
        countone+=1
    elif y[i] == 1 and countone ==0 and totalone >=2:
        #print(i,'here2')
        t+=2
        countone+=2
    elif y[i] == 1 and countone < totalone-1 and y[i-1] == 0 and totalone >=2:
        #print(i,'here3')
        t+=2
        countone+=1
    elif y[i] == 1 and countone < totalone-1 and y[i-1] == 1 and totalone >=2:
        #print(i,'here4')
        t+=2
        countone+=1
 
 
 
if t >=1 or totalone==1:
    t+=1
 
 
print(t)
