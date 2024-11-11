t=0
h=0
for i in range(int(input())):
    l=input().split()
    if l[0]=l[1]:
        t+=1
        h+=1
    elif l[0]>l[1]: t+=3
    else: h+=3
print(t,h)