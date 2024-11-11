s=input()
K=int(input())
p=set()
for i in range(len(s)):
  for j in range(1,6):
    if i+j<=len(s)-1:
      p.add(s[i:j+i])
p=sorted(p)
print(p[K-1])