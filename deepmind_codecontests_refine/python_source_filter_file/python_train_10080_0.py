s=input()
k=int(input())
l=set()
for i in  range(len(s)):
    for j in range(len(s)):
        l.add(s[i:i+j+1])
ll=list(l)
ll.sort()

print(ll[k-1])
