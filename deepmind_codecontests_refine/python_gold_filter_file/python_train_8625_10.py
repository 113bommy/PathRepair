s=input()
n=len(s)
t=0
for i in range(n):
  if s[i]=="p":
    t+=1
print(int(n/2)-t)
