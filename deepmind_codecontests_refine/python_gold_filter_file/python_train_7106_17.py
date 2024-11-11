n,m=[int(n) for n in input().split()]
arr=[int(item) for item in input().split()]
brr=[int(item) for item in input().split()]
for ans in range(2**9+1):
    ok=1
    for i in range(n):
        mil=False
        for j in range(m):
            if((arr[i]&brr[j])|ans==ans):
                mil=True
                break
        if(mil==True):
            continue
        if(mil==False):
            ok=0
            break
    if(ok==1):
        break
print(ans)    
            
            
        