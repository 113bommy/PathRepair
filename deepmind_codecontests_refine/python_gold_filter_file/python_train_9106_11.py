s = input().split()[0]
k = int(input())
n = len(s) // k
if len(s) == k:
    print("YES")
elif k*n != len(s):
    print("NO")
else:
    for i in range(k):
        #print(s[n*i:n*(i+1)], s[n*i:n*(i+1)])
        if s[n*i:n*(i+1)] != s[n*i:n*(i+1)][::-1]:
            print("NO")
            exit()
    print("YES")
