n=int(input())
l=list(input())
m=int(input())
for i in range(len(l)):
  if l[i]!=l[m-1]:
    l[i]="*"
print("".join(l))