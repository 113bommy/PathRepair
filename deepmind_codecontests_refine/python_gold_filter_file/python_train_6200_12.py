n = int(input())
dictionary = dict()
for i in input().split():
    if int(i) in dictionary:
        dictionary[int(i)]+=1
    else:
        dictionary[int(i)]=1       
powerslist = []
ans = 0  
for i in range(1,32):
    powerslist.append(2**i)
 
for i in dictionary:
    for j in powerslist:
        if j-i in dictionary:
            if j-i!=i:
                ans+=dictionary[j-i]*dictionary[i]
            else:
                ans+=(dictionary[i]-1)*(dictionary[i])
            
print(ans//2)
