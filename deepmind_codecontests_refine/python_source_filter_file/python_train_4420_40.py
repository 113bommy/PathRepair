st=input()
setst=set(st)
k=0
for i in range(len(setst)):
    if st[i] in 'qwertyuiopasdfghjklzxcvbnm':
        k+=1
print(k)