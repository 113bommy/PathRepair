x=int(input())
t=[1]
for i in range(2,32):
    j=0
    while(i**j<=x):
        t.append(i**j)
        j+=1
print(max(t))