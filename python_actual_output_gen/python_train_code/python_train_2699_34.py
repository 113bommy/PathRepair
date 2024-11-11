input()
l = list(map(int,input().split()))
n = m = 1
for i in range(len(l)-1):
    if l[i+1] < l[i]:
        m, n = n, 1
    else:
        n +=1
print(max(n,m))