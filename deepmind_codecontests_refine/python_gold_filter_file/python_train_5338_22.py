n = int(input())
a = [int(x) for x in input().split()]
total = (n-1)//2
print(total)
asort = sorted(a)
j = 0
ans = [0]*len(a)
for i in range(len(a)):
    if i%2 != 0:
        ans[i] = (asort[j])
        j += 1
    else:
        ans[i] = (asort[-(j)-1])
print(*ans)
        
    
    

        
    
        
        
    