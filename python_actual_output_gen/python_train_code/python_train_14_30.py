q,w=map(int,input().split())
count=q
while q:
  count+=q//w
  q=q//w
print(count)