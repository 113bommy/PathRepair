n = int(input())
k = n*3 + 4
print(k);print(0,0);print(0,1)
skip = 0
for i in range(n) :
    for j in range(skip,3+skip) :
        print(i+1,j)
    skip += 1
print(n+1,skip);print(n+1,skip+2)
