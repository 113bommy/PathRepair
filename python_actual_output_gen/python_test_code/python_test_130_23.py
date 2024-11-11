n= input()
m=input()
j=0
for  i in range(len(m)):
    if j ==len(m)-1:
        break
    if m[i]==n[j]:
        j+=1
print(j+1)        