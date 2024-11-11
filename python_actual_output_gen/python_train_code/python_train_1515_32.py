w,h,k=[int(i) for i in input().split()]
s=0
for i in range(k):
    s=s+2*w+2*h-4
    w=w//2
    h=h//2+1
print(s)
