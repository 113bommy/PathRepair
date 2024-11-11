#mahakaal 
n = int(input())
l = input()
m1 = []
m2 = []
n*= 2
for i in range(n//2):
    m1.append(l[i])
for i in range(n//2,n):
    m2.append(l[i])
m1.sort()
m2.sort()

x = True
if(n==2 and l[0]==l[1]):
    print("NO")
    quit()
if(m1[0]>=m2[0]):
    for i in range(1,n//2):
        if(m1[i]<=m2[i]):
            x = False
            break
if(m1[0]<m2[0]):
    for i in range(1,n//2):
        if(m1[i]>=m2[i]):
            x = False
            break
if(x):
    print("YES")
else:
    print("NO")