n,k=map(int,input().split())
heights=list(map(int,input().split()))
score = 0
ret = 0
for i in range(k):
    score += heights[i]
minscore = score
 
for i in range(1,n-k+1):
    score += heights[i+k-1] - heights[i-1]
    if score < minscore:
        minscore = score
        ret = i
 
print(ret+1)