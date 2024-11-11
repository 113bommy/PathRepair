
n=int(input())
l=sorted(list(map(int,input().split())), reverse=True)
ans=l[-1]
l.remove(l[-1])
l.insert(0,ans)
print(l)

