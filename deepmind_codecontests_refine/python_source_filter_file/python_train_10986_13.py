n = int(input())
lst = [int(i) for i in input().split()]
l=[]
for i in range(n):
    count = 1
    t = i
    while t>0 and lst[t-1]<=lst[t]:
        count+=1
        t-=1
    t = i
    while t<n-2 and lst[t]>=lst[t+1]:
        count+=1
        t+=1
    l.append(count)
print(max(l))