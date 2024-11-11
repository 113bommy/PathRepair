s=input()
res=['']
cnt=0
for i in s:
    if s==res[-1]:
        res.pop()
        cnt+=1
    else:
        res.append(i)
print ('Yes' if cnt%2==1 else 'No')