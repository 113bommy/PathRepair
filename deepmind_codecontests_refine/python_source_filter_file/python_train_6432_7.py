n=int(input())
x=list(map(int,input().split()))
p=round(sum(x)/n)
m=[]
for i in x:
  m.append((i-m)**2)
print(sum(m))