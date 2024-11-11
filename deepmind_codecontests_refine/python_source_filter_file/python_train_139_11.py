li = []
 
def appendToList(n):
    for i in range(n):
        li.append([])
 
count = 0
n = int(input())
appendToList(n)
 
for i in range(n):
    li[i] = input().split()
 
 
for i in range(n-1):
    for j in range(i+1,n-1):
        if(li[i][0] == li[j][1]):
            count += 1
        if(li[i][1] == li[j][0]):
            count += 1
print(count)