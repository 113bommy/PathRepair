name = ["A","B","C","D","E","F","G","H","I","j","k","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","Aa","Ba","Ca","Da","Ea","Fa","Ga","Ha","Ia","ja","ka","La","Ma","Na","Oa","Pa","Qa","Ra","Sa","Ta","Ua","Va","Wa","Xa","Ya","Za"]

n,k = map(int,input().split()) 
a=list(map(str,input().split()))

l = [name[i] for i in range(k-1)]
ans = [name[i] for i in range(k-1)]
j=k-1
o=k-1

for i in range(n-k+1):
    x=l.pop(0)
    
    l.append(name[o])
    o+=1
    if a[i]=="YES":
        ans.append(name[j])
        j+=1
    else:
        
        ans.append(ans[len(ans)-k+1])
print(*ans)
        
    
        
        