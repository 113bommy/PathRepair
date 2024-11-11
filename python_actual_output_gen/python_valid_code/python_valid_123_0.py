n=int(input())
pages=[]
for _ in range(n):
    l,r=map(int,input().split())
    pages.append([l,r])
k=int(input())
i=0
for g in range(len(pages)):
    if k>=pages[g][0] or k<=pages[g][1]:
        i=g
        break
print(n-i-1)
