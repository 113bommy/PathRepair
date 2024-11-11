a,b = list(map(int, input().split(" ")))
i=a
segment=[6,2,5,5,4,5,6,3,7,6]
sum=0
s=[str(i) for i in range(a,b+1)]
for i in range(10):
    sum+=s.count(str(i))*segment[i]
print(sum)