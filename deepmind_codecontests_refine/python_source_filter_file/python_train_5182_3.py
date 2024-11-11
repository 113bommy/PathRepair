N,K=map(int,input().split())
P=list(map(int,input().split()))
C=list(map(int,input().split()))

for i in range(N):
    P[i]-=1

ans=-float('inf')

for start in range(N):
    loop_len=1
    pos=P[start]
    score=C[pos]
    scores=[score]

    while pos!=start:
        loop_len+=1
        pos=P[pos]
        score+=C[pos]
        scores.append(score)
    
    loops=(K-1)//loop_len

    if score>0:
        cand=score*loops + max(scores[:(K%loop_len)])
    else:
        cand=max(scores[:min(K,loop_len)])
    ans=max(ans,cand)
print(ans)