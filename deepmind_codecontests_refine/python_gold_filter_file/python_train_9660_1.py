s=input()
N=len(s)+1

a = [0]*N
for i in range(N-1):
    if(s[i] == "<"):
        a[i+1] = a[i]+1

for j in range(N-2,-1,-1):
    if(s[j] == ">"):
        if(a[j] <= a[j+1]):
            a[j] = a[j+1]+1

print(sum(a))
