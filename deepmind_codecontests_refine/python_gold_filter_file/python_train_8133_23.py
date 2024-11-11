n, k =  [int(i)  for i in input().split()]
if k != 1 and k!=n:
    ans = (n)*2+min(k-1, n-k)+n
else:
    ans = n*3
print(ans)