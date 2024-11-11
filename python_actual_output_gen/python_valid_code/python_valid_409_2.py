n=int(input())
l=[int(i) for i in input().split()]
curr=1 
for i in l:
    if i>=curr:
        curr+=1 
print(curr)