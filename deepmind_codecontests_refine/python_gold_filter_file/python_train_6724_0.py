x,y,z=map(int,input().split())
n=int(input())
count=0
list=[int(i) for i in input().split()]
for i in range(len(list)):
    if y < list[i] and list[i] < z :
        count+=1
print(count)





