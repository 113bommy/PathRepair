n = int(input())
lst = list(map(int,input().split()))
a = 0
b = 0
end = n -1
beg = 0
for i in range(n):
    if lst[end] >= lst[beg]: 
        max = lst[end]
        end -=1
    else:
        max = lst[beg]
        beg +=1
    if  i %2 ==0:
        a += max
    else:
        b += max
    
    
    if len(lst) <= 0:
        break
print("%i %i" % (a,b))