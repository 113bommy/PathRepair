h,w=map(int,input().split())

m=0 if h%3==0 else w
n=0 if w%3==0 else h
m=min(m,n)
for i in range(1,w-1):
    s=sorted([h*i,(h//2)*(w-i),h*w-h*i-(h//2)*(w-i)])
    m=min(m,s[2]-s[0])
for i in range(1,h-1):
    s=sorted([w*i,(w//2)*(h-i),h*w-w*i-(w//2)*(h-i)])
    m=min(m,s[2]-s[0])
print(m)