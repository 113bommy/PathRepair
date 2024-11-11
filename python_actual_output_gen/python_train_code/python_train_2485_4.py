input()
a = [0]+[int(x) for x in input().split()]+[1001]

i = 1001
l = [-2]
while a!=[]:
    x = a.pop()
    if x!=i:
        l.append(-1)
        i=x-1
    else:
        l[-1]+=1
        i-=1
        
print(max(l))