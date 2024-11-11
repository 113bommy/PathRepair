n=int(input())
l=list(map(int,input().split()))
s=0
for i in l:
  s+=1/i
print(1/s)