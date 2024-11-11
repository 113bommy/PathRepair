a=int(input())
b=list(map(int,input().split()))

c=[0,abs(b[0]-b[1])]
for i in range(2,a):
  d=min(c[i-2]+abs(b[i-2]-b[i]),c[i-1]+abs(b[i-1]-b[i]))
  c.append(d)
print(c)