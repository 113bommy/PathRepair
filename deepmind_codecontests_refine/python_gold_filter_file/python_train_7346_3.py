import math
x=int(input())
k=math.floor((-1+math.sqrt(1+8*x))/2)
print(k,'\n')
for i in range(1,k):
    print(i,' ')
print(int(x-(k*(k-1)/2)))