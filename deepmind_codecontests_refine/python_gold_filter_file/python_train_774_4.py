n=int(input())
ar=sorted(list(map(int,input().split())))
m=int(input())
pair=0
ar1=sorted(list(map(int,input().split())))
for i in ar:
    if i-1 in ar1:
        ar1.remove(i-1)
        pair+=1
    elif i in ar1:
        ar1.remove(i)
        pair+=1
    elif i+1 in ar1:
        ar1.remove(i+1)
        pair+=1
print(pair)        
        
