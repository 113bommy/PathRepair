u=[]
for i in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    s=sum(a)
    u+=[(s-a[j],(i+1,j+1))for j in range(n)]
u=sorted(u)
for i in range(len(u)-1):
    if u[i][0]==u[i+1][0] and u[i][1][0]!=u[i+1][1][0]:print("Yes");print(u[i][1][0],u[i][1][1]);print(u[i+1][1][0],u[i+1][1][1]);exit()
print("NO")