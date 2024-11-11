t = int(input())
for i in range(t):
    n,k = map(int,input().split())
    X = list(map(int,input().split()))
    X.sort()
    left = []
    right = []
    for j in X:
        if j<0:
            left.append(j)
        else:
            right.append(j)
    ans = 0 
    if  len(right)>0 and len(left)>0 and abs(min(left))<max(right):
        ans = 0 
        j = len(right) - 1
        while (j>=0):
            ans += 2*right[j]
            j -= k 
        j = 0 
        while (j<len(left)):
            ans += 2*abs(left[j])
            j+= k
        ans -= max(right)
    elif len(right)>0 and len(left)>0 and abs(min(left))>max(right):
        ans = 0 
        j = len(right) - 1
        while (j>=0):
            ans +=2*right[j]
            j -= k
        j = 0 
        while (j<len(left)):
            ans += 2*abs(left[j])
            j+= k
        ans -= abs(min(left))
    elif len(right) == 0:
        ans = 0 
        
        j = 0 
        while (j<len(left)):
            ans += 2*abs(left[j])
            j+= k
        ans -= abs(left[0])
    elif len(left) == 0:
        ans = 0 
        j = len(right) - 1
        while (j>=0):
            ans += 2*right[j]
            j -= k
        ans -= right[-1]
    print(ans)
        
        
        
        
