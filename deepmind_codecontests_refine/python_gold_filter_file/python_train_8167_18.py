I=lambda:map(int,input().split())
n,t=I()
a=list(I())
c=0
while c<t-1:
    c+=a[c]
print('YNEOS'[c>=t::2])