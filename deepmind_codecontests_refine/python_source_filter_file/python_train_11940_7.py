n,p=map(int,input().split())
s=input().strip()
arr=[]
for i in range(p):
    arr.append([])
for i in range(n):
    arr[i%p].append(s[i])
flag=0
for i in range(p):
    if arr[i].count(".")==1 and len(arr[i])>=2:
        if min(arr[i].count("0"),arr[i].count("1"))==arr[i].count("0"):
            arr[i][arr[i].index(".")]="0"
        else:
            arr[i][arr[i].index(".")]="1"
        flag=1
        break
    if arr[i].count(".")>=2:
        if min(arr[i].count("0"),arr[i].count("1"))==arr[i].count("0"):
            arr[i][arr[i].index(".")]="0"
        else:
            arr[i][arr[i].index(".")]="1"
        flag=1 
        break
    if (arr[i].count("0")>0 and arr[i].count("0")<len(arr[i])) or (arr[i].count("1")>0 and arr[i].count("1")<len(arr[i])):
        flag=1 
        break
if flag==1:
    ans=[]
    for j in range(p):
        for i in range(len(arr)):
            if j<len(arr[i]):
                if arr[i][j]==".":
                    ans.append("1")
                else:    
                    ans.append(arr[i][j])
    print(arr)
    print("".join(ans))
else:
    print("No")