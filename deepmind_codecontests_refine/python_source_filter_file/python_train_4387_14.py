def split(entry):
    return [char for char in entry]
    
board = split(input())
dealt = list(input())

count = 0
for i in board:
    if i in dealt:
        count +=1
        print(count, " is the count")
    else:
        pass
    
if count >= 1:
    print("Yes")
else:
    print("No")