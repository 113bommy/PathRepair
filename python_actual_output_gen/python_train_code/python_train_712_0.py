n=int(input())
d=n
for i in range(n):d+=i
h=d>>1
a=[]
t=n
s=0
while h:
    if t<=h:h-=t;s+=t;a.append(t)
    t=min(t-1,h)

print(abs(d//2-s))
print(len(a),end=' ')
print(*a)
