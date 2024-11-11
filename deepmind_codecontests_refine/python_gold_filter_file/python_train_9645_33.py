x = int(input())

mylist = list(map(int,input().split()))
mylist = set(mylist)
mylist = list(mylist)
if mylist[0] == 0:
    print(len(mylist) - 1)
else:
    print(len(mylist))
