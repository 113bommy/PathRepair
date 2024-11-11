n=int(input())
t=0
h=n*[0]
he=0
for i in range(n):
    h[i]=int(input())
for i in range(n-1):
    t+=h[i]-he+2
    he=h[i]
    if h[i]>h[i+1]:
        t+=h[i]-h[i+1]
        he=h[i+1]
t+=1+h[-1]-he
print(t)
