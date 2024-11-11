N=int(input())
B=[9*9]+list(map(int,input().split()))+[9*9]
ans=0
for i in range(len(B)-1):
    ans+=min(B[i],B[i+1])
print(ans)