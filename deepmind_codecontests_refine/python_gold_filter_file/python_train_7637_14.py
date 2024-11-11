x=[]
a=int(input())
for i in range(a):
    x.append(int(input()))
cnt=x[0]
for i in range(1,len(x)):
    cnt+=abs(x[i-1]-x[i])+1
print(cnt+a)