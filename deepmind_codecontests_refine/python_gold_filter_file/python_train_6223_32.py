s=input()
t=input()
k=0
for i in range(len(s)-len(t)+1):
  a=s[i:len(t)+i]
  kari=0
  for j in range(len(t)):
    if a[j]==t[j]:
      kari+=1
  k=max(kari,k)
print(len(t)-k)