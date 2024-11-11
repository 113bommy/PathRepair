I=lambda:map(int,input().split())
n,t=I()
a=list(I())
c=1
while c<t:c+=a[c]
print('YNEOS'[c==t::2])