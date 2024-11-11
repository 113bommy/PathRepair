x=[1,6,28,120,496,2016,8028,32640]
y=int(input())
max=1
for i in range (0,len(x)):
  if y>=x[i] and y%x[i]==0 and x[i]>max:
    max=x[i]
print(max)