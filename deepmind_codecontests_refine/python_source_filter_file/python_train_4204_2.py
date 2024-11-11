n=int(input())
a=list(map(int,input().split()))
res=-2147483648  
for i in range(n):
    cur_xor=0
    for j in range(i+1,n):
        cur_xor=cur_xor^a[j]
        res=max(res,cur_xor)
print(res)        