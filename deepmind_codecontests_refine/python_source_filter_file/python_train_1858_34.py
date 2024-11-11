from collections import*
h,*t=open(0)
h,w=map(int,h.split())
f=o=0
for i in Counter(''.join(t)).values():f+=i//4;o+=i&1
print('YNeos'[o-h%2>h*w%2or f<h//2*w//2+h//4::2])