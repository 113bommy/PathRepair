n=int(input())
l = list(map(int,input().split()))
sum=0
for i in range(n-2):
  if l[i]<l[i+1]<l[i+2] or l[i]>l[i+1]>l[i+2]:
    sum+=1
print(sum)