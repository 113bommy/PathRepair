#editorial implementation
n = int(input())
m  = (n+1)//2
a = list(map(int, input().split()))
curr = 0
for i in range(m):
    curr+=a[2*i]
answer = curr
for j in range(n-1):
    curr-= a[(2*j)%n]
    curr+= a[(2*(j+m))%n]
    answer = max(answer,curr)
print(answer)
    

