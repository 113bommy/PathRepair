na = input().strip().split(' ')
n = int(na[0])
a = int(na[1])
c = input().strip().split(' ')
c = [int(ci) for ci in c]
i = a-1
j = a-1

count = 0
while i>=0 and j<=n-1:
    if i==j and c[i]==1:
        count += 1
    elif c[i]==c[j] and c[i]==1:
        count += 2
    i -= 1
    j += 1 

if i>=0:
    count += sum(c[:i+1])
elif j<=n-1:
    count += sum(c[j:])
    
print(count)