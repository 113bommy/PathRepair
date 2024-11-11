x = input()
n = len(x)

for i in range(n-1):
  for j in range(i+1,n):
    if(x[:i]+x[j:]=="CODEFORCES"):
        print("YES")
        exit(0)
print("NO")
exit(0)