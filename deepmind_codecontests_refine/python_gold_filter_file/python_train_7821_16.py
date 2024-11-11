n = int(input())
a = [int(x) for x in input().split()]
#print(a)
ans = a[len(a)-1]
#print(ans)
prev = a[len(a)-1]
for i in range(len(a)-1, 0, -1):
    if a[i-1] < prev:
        ans += a[i-1]
        prev = a[i-1]
        #print("prev:", i, prev, ans)
    else:
        if prev > 0:
            prev = prev-1
            ans += prev
        else:
            break
        #print("no:", i, prev, ans)
print(ans)



