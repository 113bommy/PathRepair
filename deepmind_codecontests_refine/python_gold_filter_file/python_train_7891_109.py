w=input()
ans=1000
for i in range(len(w)-2):
  ans=min(ans, abs(753-int(w[i:i+3])))
print(ans)