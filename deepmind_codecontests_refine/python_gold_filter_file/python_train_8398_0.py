import heapq
n=int(input())
w=[int(x) for x in input().split()]
us={w[i]:i+1 for i in range(n)}
w.sort()
p=input()
order=""
i=0
seats=[]
for x in p:
    if x=="0":
        y=w[i]
        order+=str(us[y])+" "
        heapq.heappush(seats,-y)
        i+=1;
    else:
        m=heapq.heappop(seats)
        order+=str(us[-m])+" "
print(order)