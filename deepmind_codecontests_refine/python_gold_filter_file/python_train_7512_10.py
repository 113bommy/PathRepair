#n = int(input())
n,k=map(int, input().split())
arr = list(map(int, input().split()))
a=[]
ans=arr[-1]-arr[0]
for i in range(n-1):
    a.append(-arr[i+1]+arr[i])
a.sort()
#print(a)
print(ans+sum(a[:k-1]))


#print(p)
#for _ in range(int(input())):
#l,r=map(int, input().split())




