k,l,m,n,d=int(input()),int(input()),int(input()),int(input()),int(input()),
s=0
for i in range(d):
    if i%k==0 or i%l==0 or i%m==0 or i%n==0:
        s+=1
print(s)