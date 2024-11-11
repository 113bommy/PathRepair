N=int(input())
B=map(int,input().split())
sum=B[0]
for i in range(len(B)-1):
  sum+=min(B[i],B[i+1])
sum+=B[-1]
print(sum)