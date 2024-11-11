n=int(input())
q,w,r=[],[],[]
for x in input().split('.'):q+=x.split('!')
for x in q:w+=x.split('?')
for x in w:
    if x:r+=[x.strip()+'.']
i=0
while i<len(r):
    if len(r[i])>=n:print('Impossible');exit()
    while i+1<len(r) and len(r[i])+len(r[i+1])+1<=n:r[i]+='.'+r[i+1];r.pop(i+1)
    i+=1
print(i)