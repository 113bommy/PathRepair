h,w=map(int,input().split())
print([1,sum(divmod(h*w, 2))][h>0<w])