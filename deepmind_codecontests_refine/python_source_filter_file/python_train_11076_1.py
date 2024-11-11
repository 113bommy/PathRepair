r=input()
S=r.split('heavy')
k=0
for i in range(len(S)) :
    p=S[i].count('metal')
    k=k+i*p
print(S)
print(k)
    
