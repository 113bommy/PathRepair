n=int(input())
first=[int(x) for x in input().split()]
second = [int(x) for x in input().split()]
third = [int(x) for x in input().split()]
first.sort() , second.sort() , third.sort()
for i in range(n-1):
    if first[i]!=second[i]:
        print(first[i])
        count=1
        break
    else:
        count=0
if count==0 and i==n-1:
    print(first[n-1])
    
for j in range(n-2):
    if second[j]!=third[j]:
        print(second[j])
        count=1
        break
    else:
        count=0
        
if count==0 and i==n-2:
    print(second[n-2])
    