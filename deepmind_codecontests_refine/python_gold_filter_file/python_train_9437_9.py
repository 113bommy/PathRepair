x=input()
s=[x[0]]
c=[x.count(x[0])]
for i in x[1:]:    
    if i not in s:
        s+=[i]
        c+=[x.count(i)]
if len(s)==4:
    print("YES")
elif len(s)==2 and c[0]>1 and c[1]>1:
    print("YES")
elif len(s)==3 and (c[0]>1 or c[1]>1 or c[2]>1):
    print("YES")
else:
    print("NO")

