# cook your dish here

n,k = map(int,input().split())
l=[]
for i in range(n):
    a,b = map(int,input().split())
    l.append([-a,b])

l.sort()
print(l.count(l[k-1]))