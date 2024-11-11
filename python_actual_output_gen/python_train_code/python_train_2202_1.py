n=int(input())
l=[int(i) for i in input().split()]
mini=19**4
mini=min(mini,l[0],l[n-1])
for i in range(1,n-1,2):
    mini=min(mini,max(l[i],l[i+1]))
print(mini)