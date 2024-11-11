box={}
n=int(input())
for i in range(n):
    v=input()
    if v in box:
        box[v]+=1
    else:
        box[v]=1
m=max(box.values())
f=[k for k,v in box.items() if v==m]
print('\n'.join(f))