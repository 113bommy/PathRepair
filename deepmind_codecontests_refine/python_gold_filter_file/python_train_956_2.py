n,m,d = map(int,input().split())
l = list(map(int,input().split()))
s = sum(l)
ans = [0]*n
last =-1
ptr = 0
us = 0
for i in range(n):
    if(s>=n-d-i+1 and s>0):
        last = i
        break
    if(i-last>=d):
        if(ptr>=m):
            print("NO")
            exit(0)
        if(us!=l[ptr]):
            ans[i] = ptr+1
            us+=1
            s-=1
        if (us == l[ptr]):
            ptr+=1
            last = i
            us = 0
for i in range(ptr,m):
    for j in range(l[i]):
        ans[last]= i+1
        last+=1
print("YES")
for i in ans:
    print(i,end = " ")



