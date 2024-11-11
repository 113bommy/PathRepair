i=int(input())
ans=[]
for n in range(i):
    L,v,l,r=map(int,input().split())
    ans.append((l-1)//v + (L)//v - (r+1)//v +1)
for i in ans:
    print(i)