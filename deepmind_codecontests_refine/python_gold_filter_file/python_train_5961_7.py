n=int(input())

arr=[(0,0),(0,1),(1,1),(1,0)]
i=1
j=1
for k in range(n):
    arr.append((i+1,j))
    arr.append((i,j+1))
    arr.append((i+1,j+1))
    i+=1
    j+=1

print(len(arr))
for k in arr:
    print(k[0],k[1])
    