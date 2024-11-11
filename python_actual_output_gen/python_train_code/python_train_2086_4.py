def isvalid(li):
    for i in li:
        if(i%2):
            return 1
    return 0
n=int(input())
l=input().split()
li=[int(i) for i in l]
if(isvalid(li)):
    li.sort()
    for i in li:
        print(i,end=" ")
    print()
else:
    for i in li:
        print(i,end=" ")
    print()
