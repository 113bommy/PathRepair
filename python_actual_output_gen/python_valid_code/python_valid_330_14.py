n, m = input().split()
s = input()
t = input()
n = int(n)
m = int(m)
k = n
pos = []
aux = []

for i in range(m - n + 1):
  x = n
  aux=[]

  for j in range(len(s)):
    if(t[i + j] == s[j]):
      x -= 1
    else:
      aux.append(str(j+1))

    j += 1

  if(x < k):
    k = x
    pos = aux


print(k)
print(' '.join(pos))