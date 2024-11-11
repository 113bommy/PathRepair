n = int(input())
a = [int(x) for x in input().split()]
maxi=max(a);ans=0
for i in a: ans+= maxi-i
print(ans)