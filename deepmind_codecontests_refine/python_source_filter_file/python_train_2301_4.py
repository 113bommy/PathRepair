n,k = input().split(" ")
n = int(n)
k = int(k)
d = {}

for i in input().split(" "):
    a = int(i)
    if a in d.keys():
        d[a]+=1
    else:
        d[a]=1
        
num = k
for i in d.values():
    if i > num:
        if i%k:
            num = k*(i//k + 1)
        else:
            num = i

print(d)
print((num*len(d)) - n)



    
