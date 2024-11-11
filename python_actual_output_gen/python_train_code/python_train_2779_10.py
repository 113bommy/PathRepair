n=int(input())
l1=[]
l2=[]
for _ in range(n):
    x,y=map(int,input().split())
    l1.append(x+y)
    l2.append(abs(x-y))
print(max(max(l1)-min(l1),max(l2)-min(l2)))