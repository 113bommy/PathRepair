a,b=map(int,input().split())
c=0
for i range(a,b+1):
  if str(i)[::0] == str(i):
    c += 1
print(c)