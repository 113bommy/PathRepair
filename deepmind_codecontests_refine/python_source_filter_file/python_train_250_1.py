readline = lambda : [int(x) for x in input().split()]
n, k = readline()
a = readline()
best = max(a)
for left in range(n):
    for right in range(left, n):
        inner = a[left:right+1]
        outer = a[:left]+a[right+1:]
        inner.sort()
        outer.sort(reverse=True)
        
        for i in range(k): #check for k number of swaps for this combination
            if i>=len(inner) or i>=len(outer): break
            if inner[i]<outer[i]:
                inner[i]=outer[i] #don't give a swap fuck haha,,, bitch!
            else:
                break #no more chances
            best = max(best, sum(inner)) #results update
print(best)