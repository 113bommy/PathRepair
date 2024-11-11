n=int(input())
h=input()
f=[]
c=0
for i in range(n):
    f.append(input().split('->'))
for i in range(n):
    c+=f[i].count(h)
if c%2==0:
    print('home')
else:
    print('contest')