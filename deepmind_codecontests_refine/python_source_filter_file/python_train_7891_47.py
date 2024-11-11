s=int(input())
ans=753
while ans>99:
  ans=min(ans,abs(s%1000-753))
  s=s//10
print(ans)