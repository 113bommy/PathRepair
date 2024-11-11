a=['ogo']
for i in range(46):
    s=a[-1]+'go'
    a.append(s)
ans=[]
n=int(input())
s=input()
i=0
while (i<n):
    flag=0
    for j in reversed(a):
        if s[i:].startswith(j):
            ans.append('***')
            flag=1
            break
    if flag==0:
        ans.append(s[i])
        i+=1
    else:i+=len(j)
print(''.join(ans))

        

