n=int(input())
h=list(map(int,input().split()))
DP=[0,abs(h[0]-h[1])]
for i in range(n-2):
    DP+=[min(DP[-1]+abs(h[i]-h[i+1]),DP[-2]+abs(h[i]-h[i+2]))]
print(DP[-1])