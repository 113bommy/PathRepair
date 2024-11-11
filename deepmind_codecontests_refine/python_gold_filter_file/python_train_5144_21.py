l1 = input().split()
n = int(l1[0])
m = int(l1[1])
l = list(map(int,input().split(None,n)[:n]))
k = []
for i in l:
  if(i<0):
    k.append(i)
k.sort()
aux = len(k)
j = 0
cont = 0
for i in range(aux):
  if not(j>=m):
    cont+=k[i]
    j+=1
print(cont*-1)