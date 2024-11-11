n=int(input())
l=list(map(int,input().split()))
num=[0]*(10**5+1)
for i in l:
    num[i]+=1
q=int(input())
count=sum(l)
for _ in range(q):
    b,c=map(int,input().split())
    count+=num[b]*(c-b)
    num[c]+=num[b]
    num[b]==0
    print(count)