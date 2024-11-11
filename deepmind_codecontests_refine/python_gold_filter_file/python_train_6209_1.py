f,l = input().split(' ')
ans =''
ans+=f[0]
i = 1
j = 0
while(True):
    if(i==len(f)):
        ans+=l[j]
        break
    x = ord(f[i])
    y = ord(l[j])
    if(x<y):
        ans+=f[i]
        i+=1
    else:
        ans+=l[j]
        break
print(ans)