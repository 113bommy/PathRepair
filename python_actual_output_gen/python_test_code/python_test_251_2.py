n=int(input())
B=list(map(int,input().split()))
A=[]
for i in range(n):
    for j in range(len(B))[::-1]:
        if B[j]==j+1:
            A.append(B.pop(j))
            break
    else:print(-1);break
for i in A[::-1]:print(i)