def proB(n):
    ans=0
    for i in range(60):
        ans+= (n// (1<<i))
    return ans
t=int(input())
for i in range(t):
    n=int(input())
    print(proB(n))