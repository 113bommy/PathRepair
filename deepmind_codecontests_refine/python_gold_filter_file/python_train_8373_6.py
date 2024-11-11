b,d,c='','',0
for a in input().split():b+=a
for a in input().split(): d+=a
for i in d:
    if i not in b:
        c=1
        break
    else:
        b=b.replace(i,"",1)

if c==1:
    print("NO")
else:
    print("YES")