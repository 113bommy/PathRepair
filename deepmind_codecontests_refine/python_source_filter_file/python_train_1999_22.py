n,k=map(int,input().split())
l=list(map(int,input().split()))
s=[]
x=0
for i in l:
    if i not in s:
        s.append(i)
        x+=1
    if x>k:
        s.pop(0)
        x-=1
print(*s[::-1])