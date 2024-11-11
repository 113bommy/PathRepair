n=input()
l=list(map(int, input().split()))

count=0

while all(i/2==0 for i in l):
  l=[i/2 for i in l]
  count+=1
  
print(count)