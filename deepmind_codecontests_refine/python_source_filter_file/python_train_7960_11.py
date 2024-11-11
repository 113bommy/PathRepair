l=[[0],[0],[2],[3],[2,2,3],[5],[3,5],[7],[2,2,2,7],[3,3,3,7]]
n=int(input())
s=input()
ans=[]
for i in s:
    if(i=='0' or i=='1'):
        continue
    else:
        s=len(l[int(i)])
        for j in range(s):
            ans.append(str(l[int(i)][j]))
ans.sort()
ans=ans[::-1]
s="".join(ans)
print("".join(ans))
