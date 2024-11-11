n,d = map(int,input().split())
s = list(map(int,input().split()))
p = list(map(int,input().split()))
d -= 1
maxHis = s[d]+p[0]
# i is the index for current scores
i = n-1
# j is the index for the points earned
j = 1
count = 0
while (j<n):
    if (i==d):
        i -= 1
    else:
        while (j<n and s[i]+p[j]>=maxHis):
            j += 1
        if (j==n):
            break
        else:
            j += 1
            count += 1
            i -= 1
print(n-count)
 
