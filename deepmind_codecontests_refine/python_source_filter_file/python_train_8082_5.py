n = int(input())
arr = list(map(int,input().split()))
even = 0
odd = 0
for i in arr:
    if i%2==0:
        even+=1
    else:
        odd+=1
if odd==0:
    print(0)
elif odd < even:
    print(odd)

elif odd==even:
    print(odd)
else:
    print (even + int(odd//3))
