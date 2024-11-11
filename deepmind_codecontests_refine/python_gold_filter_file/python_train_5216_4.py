n = int(input())
l = list(map(int,input().split()))
mx = 1
e,s = 0,0
for i in range(1,n):
    if(l[i]>2*l[i-1]):
        e,s = i,i
    else:
        e+=1
        mx = max(mx,e-s+1)
print(mx)