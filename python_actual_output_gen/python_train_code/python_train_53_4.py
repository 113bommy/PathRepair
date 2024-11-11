s=input()
l=[]
for i in range(len(s)):
    if i%2==0:
        l.append(s[i])
    else:continue
l.sort()
print(l)
os=''
for e in l:
    os+=str(e)
    os+='+'
print(os[0:len(os)-1])