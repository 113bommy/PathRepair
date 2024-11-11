mod_number=10000000007
n,m=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))

ans_x=0
ans_y=0

for i in range(n-1):
    ans_x += (x[i+1]-x[i])*(i+1)*(n-i-1) % mod_number


for i in range(m-1):
    ans_y += (y[i+1]-y[i])*(i+1)*(m-i-1) % mod_number

print(ans_x * ans_y % mod_number)