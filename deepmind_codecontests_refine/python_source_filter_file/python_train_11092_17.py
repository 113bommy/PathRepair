n,ans = int(input()),10e6
sat = [i for i in input()]
mat = list(map(int,input().split())) 
for i in range(n-1):
    if sat[i]== "R" and sat[i+1]=="L":
        ans = min(ans,(mat[i+1]-mat[i] + 1) // 2)
print("-1" if ans==10e6 else ans)