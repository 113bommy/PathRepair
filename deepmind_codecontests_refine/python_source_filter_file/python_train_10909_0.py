def f(s,l=3):
  if l==1:
    return len(set(s))
  a=0
  for i in set(s):
    a+=f(s[s.index(i)+1:],l-1)
  return a

n=int(input())
s=input()
print(f(s)i)
