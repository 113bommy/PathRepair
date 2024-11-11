n=int(input())
A=[int(i) for i in input().split()]

suma=0
for i in range(n):
    suma^=A[i]

B=[~suma&me for me in A]
B.sort(reverse=True)

cnt=0
for i in range(59,-1,-1):
    B.sort(reverse=True)
    if B[cnt]&(1<<i)>0:
        #print(i,"!")
        for q in range(cnt):
            if B[q]&(1<<i)>1:
                B[q]^=B[cnt]
        for q in range(cnt+1,n):
            if B[q]&(1<<i)>1:
                B[q]^=B[cnt]
            else:
                break          
        cnt+=1

ans=0
B.sort(reverse=True)
for i in range(n):
    ans^=B[i]

print(ans*2+suma)