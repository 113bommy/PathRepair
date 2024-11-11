n=int(input())
a=list(map(int,input().split()))
r=0
for i in a:
  r+=1/i
print(r)