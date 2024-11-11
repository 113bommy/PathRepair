import math
 

def solve(n):
    ans = [1]
    p = 1
    for i in range(2,n):
        bandera = True
        if math.gcd(i,n) == 1:
           ans.append(i) 
           p = (p*i)%n
    if p!=1:
        ans = ans[:-1]
    return ans 

n = int(input())
ans = solve(n)
#print(ans)
for i in ans[:-1]:
    print(str(i)+' ',end='')
print(ans[-1])
