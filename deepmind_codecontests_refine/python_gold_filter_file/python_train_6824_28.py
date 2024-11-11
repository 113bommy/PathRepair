n = int(input())

cost=[]
cost=input()
cost=cost.split(" ")
for i in range(n):
	cost[i]=int(cost[i])
prev=input()
left=[]
right=[]
left.append(0)
right.append(cost[0])
for i in range(1,n):
    curr=input()
    if left[i-1]==-1 and right[i-1]==-1:
        left.append(-1)
        right.append(-1)
    elif left[i-1]>=0 and right[i-1]==-1:
        if curr>=prev:
            left.append(left[i-1])
        else:
            left.append(-1)
        if curr[::-1]>=prev:
            right.append(left[i-1]+cost[i])
        else:
            right.append(-1)
    elif left[i-1]==-1 and right[i-1]>=0:
        
        if curr>=prev[::-1]:
            left.append(right[i-1])
        else:
            left.append(-1)
        if curr[::-1]>=prev[::-1]:
            right.append(right[i-1]+cost[i])
        else:
            right.append(-1)
    else:
        if curr>=prev and curr>=prev[::-1]:
            left.append(min(left[i-1],right[i-1]))
        elif curr>=prev :
            left.append(left[i-1])
        elif curr>=prev[::-1]:
            left.append(right[i-1])
        else:
            left.append(-1)
        if curr[::-1]>=prev and curr[::-1]>=prev[::-1]:
            right.append(min(left[i-1],right[i-1])+cost[i])
        elif curr[::-1]>=prev :
            right.append(left[i-1]+cost[i])
        elif curr[::-1]>=prev[::-1]:
            right.append(right[i-1]+cost[i])
        else:
            right.append(-1)
    prev = curr[:]

 	
if left[n-1]>=0 and right[n-1]>=0:
	print(min(left[n-1],right[n-1]))
elif left[n-1]>=0:
	print(left[n-1])
else:
	print(right[n-1])
