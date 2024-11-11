f,l=map(str,input().split())
i=1
j=0
while i<len(f):
    if ord(f[i])<ord(f[j]):
        i+=1
    else:
        break
print(f[0:i]+l[0])
    
