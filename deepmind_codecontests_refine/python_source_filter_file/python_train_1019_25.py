n=int(input())
s=input()
b_c=0
b_t=s.count("#")
ans=b_t
for i in range(n):
  a=i-b_c+(n-i)-(b_t-b_c)
  ans=min(a,ans)
  if s[i]=="#":
    b_c+=1
print(ans)