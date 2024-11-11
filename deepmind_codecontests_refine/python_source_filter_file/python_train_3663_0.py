n=int(input())
s=input().split()
a_s=[]
for a in s:
  a_s.append(int(a))
a=sorted(a_s,reverse=True)
print(a)
l=""
count=0
c=0
for i in a:
  count+=i*c+1
  l+=str(s.index(str(i))+1)+" "
  s[s.index(str(i))]=-1
  c+=1
print(count)
print(l)