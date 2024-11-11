import math;n=int(input());print((math.ceil(n/2)**2+(n//2)**2));k="."*n;p="."*n;h=1
for i in range(n):
    if i%2!=0:k=k[:i]+"c"+k[i+1:]
    else:p=p[:i]+"c"+p[i+1:]
while(h<=n):print(p if h%2 else k );h+=1