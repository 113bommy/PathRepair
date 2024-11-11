s=int(input())
a=[s]
i=1
while len(a)==len(set(a)):
  if a[i-1]%2=0:
    a.append(a[i-1]//2)
  else:
    a.append(a[i-1]*3+1)
  i+=1
print(i)