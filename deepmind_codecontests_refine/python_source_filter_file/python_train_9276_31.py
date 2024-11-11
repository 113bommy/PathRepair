t=int(input())
arr = []
for i in range(t):
       arr2= []
       for j in range(101):
             arr2.append(0)
       arr.append(arr2)
for i in range(t):
       arr3 = [int(x) for x in input().split()]
       for j in range(len(arr3)):
              arr[i][arr3[j]]=1
    
    
for j in range(101):
    co=0
    for i in range(t):
         if arr[i][j]==1:
             co+=1 
    if co==t:
        print(j,end=" ")

      