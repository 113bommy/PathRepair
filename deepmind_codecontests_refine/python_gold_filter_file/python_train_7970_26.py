problems, minutes = map(int, input().split())
solved = 0
taken= 0
time = 240-minutes
for i in range(1,problems+1):
    taken += i*5
    if taken>time:
        break
    else:
        solved+=1
        
print(solved)