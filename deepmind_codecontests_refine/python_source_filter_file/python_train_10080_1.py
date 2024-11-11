s=list(input())
k=int(input())
t=set({})
print(s)
for i in range(min(k,len(s))):
    for j in range(len(s)-i):
        t.add("".join(s[j:i+j+1]))
print(sorted(t)[k-1])  