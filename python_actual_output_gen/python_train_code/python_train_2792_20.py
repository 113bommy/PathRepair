n, k =  [int(i)  for i in input().split()]
if k != 1 and k!=n:
    ans = (n)*3+min(k, n-k)
else:
    ans = n*3
print(ans)