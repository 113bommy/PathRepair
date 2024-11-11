s=input()
l=[]
for i in s:l.append((123-ord(i))%26)
k=int(input())
for i,j in enumerate(l):
    if j<=k:l[i],k=26,k-j
l[-1]=(l[-1]-k)+[0,26][l[-1]-k<1]
for i,j in enumerate(l):l[i]=chr(123-j)
print(''.join(map(str,l)))