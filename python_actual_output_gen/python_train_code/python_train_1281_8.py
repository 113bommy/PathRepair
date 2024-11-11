n,a,b,c =map(int,input().split())
array = list(map(int,input().split()))


val_max = (10**18+1)*-1

array_b =[]
for x in range(n):
    if (a*array[x]>val_max):
        val_max = a*array[x]
    array_b.append(b*array[x]+val_max)

resp = (10**18+1)*-1
val_max = (10**18+1)*-1
for y in range(n):
    if (c*array[n-y-1]> val_max):
         val_max =c*array[n-y-1]
    if (array_b[n-y-1]+val_max)>resp:
        resp = array_b[n-y-1]+val_max

print(resp)
    
        
