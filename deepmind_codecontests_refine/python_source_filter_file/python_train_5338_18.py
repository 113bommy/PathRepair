# Fear defeats more people than any other one thing in the world.
# by : Blue Edge - Create some chaos

n = int(input())
a = list(map(int,input().split()))
a.sort()
print((n-1)//2)
b = []
i = 0
j = n-1
while i<j:
    b+=a[j],
    j-=1
    b+=a[i],
    i+=1

if n&1:
    b+=(n//2 + 1),

print(*b)
