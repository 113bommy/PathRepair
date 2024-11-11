n = int(input())
t = list(map(int,input().split()))
odd = 0
even = 0
for x in t:
    if x%2 == 0:
        even+=1
    else:
        odd+1
if even == odd == 0:
    print(' '.join(str(z)for z in t))
else:
    t = sorted(t)
    print(' '.join(str(z) for z in t))