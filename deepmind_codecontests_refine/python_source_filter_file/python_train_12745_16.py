n, p, k = list(map(int,input().split()))

if(p - k > 1):
    print("<< ",end="")
for i in range(k):
    if(p - k + i >= 1):
        print(p - k + i,end=" ")

print("(",end="")
print(p,end=") ")

for i in range(k):
    if(p + i + 1 <= n):
        print(p + i + 1,end=" ")

if(p + k + 1 < n):
    print(">>")
