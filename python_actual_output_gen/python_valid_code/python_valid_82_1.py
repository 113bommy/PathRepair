n=int(input())
s=input()
arr=[int(s[i]) for i in range(len(s))]
t=[]
for i in range(n):
    t.append([int(x) for x in input().split()])
ans=sum(arr)
for i in range(2000):
    for j in range(n):
        if i<=t[j][1] and (i-t[j][1]) % t[j][0] == 0:
            if arr[j] == 1:
                arr[j]=0
            else:
                arr[j]=1
    ans=max(ans,sum(arr))
print(ans)