y=int(input())
for x in range(y+1,9002):
    count=len(set(str(x)))
    if count==4:
        break
    
print(x)