n= int(input())
l=[]
for _ in range(n):
    s= input()
    l.append(s)
l.sort(key= len)
m=0
for i in range(n):
    c=0
    for j in range(0,i+1):
        if l[j] in l[i]:
            c+=1
    if c== i:
        m+=1
if m== n:
    print("YES")
    for i in l:
        print(i)
else:
    print("NO")