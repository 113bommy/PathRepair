n,k = list(map(int,input().split()))
l = 0
h = n-1
a = []
lside = 0
rside = 1
while True:
    rem = n - (lside+rside)
    if rem%(2*k+1)==0:
        a.append(l)
        a.append(h)
    if h+k > n-1:
        h-=1
        rside += 1
    elif l<k:
        l+=1
        lside += 1
    else:
        break

start = a[0]+1
end = a[1]+1
output = list(range(start,end+1,2*k+1))
print(len(output))
print(*output)