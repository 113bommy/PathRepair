n,l,h=input().split()
n=int(n)
l=int(l)
h=int(h)
if l>0 and h>0:
    print(h//n-l//2)
else:
    print(h//n+abs(l)//n+1)
        
        
