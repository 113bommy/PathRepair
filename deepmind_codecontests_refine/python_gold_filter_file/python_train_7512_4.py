n,k = [int(u) for u in input().split()]
a = [int(u) for u in input().split()]
 
ans = a[-1]-a[0]
diff = [a[i-1]-a[i] for i in range(1,len(a))]
diff.sort()

ans += sum(diff[0:k-1])
print(ans)