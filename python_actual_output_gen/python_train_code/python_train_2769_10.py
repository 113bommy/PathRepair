n=int(input())
li=list()
line=input()
lines=line.split()
for i in range(n):
    a=int(lines[i])
    li.append(a)
li.sort()
if n==1:
    print(li[0])
if n==2:
    print(li[0]+li[1])
if n>=3:
    t=0
    for i in range(n-2):
        t= t + (i+2)*li[i]
    t+=n*li[n-2]
    t+=n*li[n-1]
    print(t)
    
