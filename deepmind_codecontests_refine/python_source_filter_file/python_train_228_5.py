import time

start=time.time()

t=int(input())

for _ in range(t):
    n, m=map(int ,input().split())
    s=input()
    p=list(map(int, input().split()))

    alpha=[0]*26
    st=[0]*n

    for i in p:
        st[i-1]+=1

    for j in range(n-1, 0, -1):
        st[j-1]+=st[j]
    
    for k in range(n):
        alpha[ord(s[k])-97]+=st[k]
        alpha[ord(s[k])-97]+=1

    print(*alpha)
print(time.time()-start)