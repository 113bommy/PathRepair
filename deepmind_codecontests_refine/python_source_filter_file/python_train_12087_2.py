input()
myList = [int(item) for item in input().split()]
if sum(myList) == 1:
    print("HARD",end='\n')
else:
    print("EASY",end='\n')