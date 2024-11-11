n=int(input())
f=list(map(int,input().split()))
f.sort();t=0;answer=0
for i in range(n):
    if t<=f[i]:
        answer+=1
        t+=f[i]
print(answer)