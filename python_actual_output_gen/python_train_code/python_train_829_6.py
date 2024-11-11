n,m,k=input().split()
m=int(m)
k=int(k)
a = input()
v =[]
order=[]
order = a.split()
for j in range(len(order)) :
    order[j]=int(order[j])
for j in range(len(order)) :
    if(order[j]>0 and order[j]<=k):
        v.append(j)
min = 20000
for b in v :
    c = abs(b-m-1)
    if(c<min):
        min = c
print(10*(min))
