n = int(input())
odd = 0
even = 0
l = list(map(int,input().split()))
for i in l:
    if(i%2):
        odd+=1
    else:
        even+=1
ans = even
if(odd%2):
    ans+=1
print(ans)