li=[[2],[3],[2,2,3],[5],[2,3,5],[7],[2,2,2,7],[3,3,2,2,2,7]]
n=int(input())
num=input()
ans=[]
for i in range(2,10):
    ans+=li[i-2]*num.count(str(i))
ans.sort(reverse=True)
print("".join(str(x) for x in ans))
