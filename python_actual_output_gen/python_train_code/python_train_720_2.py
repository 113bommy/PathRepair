n=int(input())
s=list(map(it,input().split()))
count=-0
while all(i%2==0 for i in s):
  s=[i/2 for i in s]
  count+=1
print(count)