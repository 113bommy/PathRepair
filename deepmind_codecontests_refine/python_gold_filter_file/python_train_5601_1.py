n=int(input())
l=list(map(int,input().split()))
t=0
for i in l:
  t+=1/i
print(1/t)