A,B = map(int,input().split())
ans=-1
for i in range(1,101):
  if i*0.08//1==A and i*0.1//1==B:
    ans=i
    break
print(ans)