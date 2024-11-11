n=int(input())
l=sorted([list(map(int,input().split())) for nd in range(n)],key=lambda x: x[1])
now=0
for a,s in l:
  if a+now>s:print("No");exit()
  now+=a
else:print("Yes")