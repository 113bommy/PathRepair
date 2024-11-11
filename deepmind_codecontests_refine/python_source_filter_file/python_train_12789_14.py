a=input()
b=input()
ans=''
for x,y in zip(a,b):
  ans += (x+y)
print(ans if len(a) == len(b) else ans + b[-1])