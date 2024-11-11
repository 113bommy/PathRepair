lst=[]
k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
for i in range(1,d+1,k):
    lst.append(i)
for i in range(1,d+1,l):
    lst.append(i)
for i in range(1,d+1,m):
    lst.append(i)
for i in range(1,d+1,n):
    lst.append(i)
print(len(set(lst)))