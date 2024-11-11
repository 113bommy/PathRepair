s=input()
s=s[::-1]
l=len(s)
num=0
for i in range(l):
  num+=int(s[i])*(2**i)
ans=0
for i in range(20):
    if num>4**i:
        ans+=1
print(ans)