a1 = int(input()) # first team players
a2 = int(input()) # second team players
k1 = int(input()) # cards to get kicked
k2 = int(input()) # cards to get kicked
n  = int(input()) # cards given

# min
ans = n - ((a1*(k1-1)) + (a2*(k2-1)))
print(max(ans,0),end=' ')

# max
ans = 0

if k1<=k2:
    while n-k1>=0 and a1>0:
        a1-=1
        n-=k1
        ans+=1
    while n-k2>=0 and a2>0:
        a2-=1
        n-=k2
        ans+=1
else: 
    while n-k2>=0 and a2>0:
        a2-=1
        n-=k2
        ans+=1
    while n-k1>=0 and a1>0:
        a1-=1
        n-=k1
        ans+=1

print(ans)
