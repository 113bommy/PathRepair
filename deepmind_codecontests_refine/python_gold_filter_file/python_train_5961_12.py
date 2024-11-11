k=int(input())
n,l=k+1,[]
for i in range(n+1):
    for j in range(i-1,i+2):
        if j<0 or j>n:
            continue
        else:
            l.append([i,j])
print(len(l))
for i in l:
    print(str(i[0])+" "+str(i[1]))

    
