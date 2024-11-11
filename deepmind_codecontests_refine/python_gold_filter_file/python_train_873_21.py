n,k=map(int,input().split())
count=0
Num={str(i) for i in range(k+1)}

for i in range(n):
    if set(input())>=Num:
        count+=1
print(count)