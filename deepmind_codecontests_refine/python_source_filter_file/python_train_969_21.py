n=int(input())
A=list(map(int,input().split()))
count=0
D=[]
for i in A:
    if i not in D:
        D.append(i)
        if max(D)==i:
            count+=1
        elif min(D)==i:
            count+=1
print(count)