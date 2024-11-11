a,b,c=map(int,input().split())
s=0
ma=max(a,b,c)
mi=min(a,b,c)
me=a+b+c-ma-mi
for i in range(mi+1):
    if (mi+me-2*i)==ma:
        s=1
        break
#print(i)
if s==0:
    print("Impossible")
else:
    mime=i
    mima=mi-mime
    mame=me-mime
    if a==mi and b==me:
        print(mime,mame,mima)
    elif a==mi and b==ma:
        print(mima,mame,mime)
    elif a==me and b==mi:
        print(mime,mima,mame)
    elif a==me and b==ma:
        print(mima,mima,mime)
    elif a==ma and b==mi:
        print(mima,mime,mame)
    else:
        print(mame,mime,mima)
    