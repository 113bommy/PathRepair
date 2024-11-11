n=int(input())
s=list(input())
k=int(input())
l=s[k-1]
for i in range(n):
  if s[i]!=l:
    s[i]="*"
print("".join(s))