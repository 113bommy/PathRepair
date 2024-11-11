n,k=map(int,input().split())
a=[]
for i in range(n):
    a.append(eval(input().replace(' ','*(300-')+')'))
a.sort()
a.reverse()
print(a.count(a[k-1]))
