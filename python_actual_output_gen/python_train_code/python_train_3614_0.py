Rank=0
for i in range(int(input())):
    A=list(map(int,input().split()))
    if i==0:
        M=sum(A)
    else:
        if sum(A)>M:
            Rank+=1
print(Rank)