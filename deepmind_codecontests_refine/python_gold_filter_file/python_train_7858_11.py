n=int(input())
t=list(map(int,input().split()))
r=[1]
p=1
for i in range (len(t)-1):
  if t[i]<=t[i+1]:
    p+=1
    r.append(p)
  else:
    p=1
print(max(r))