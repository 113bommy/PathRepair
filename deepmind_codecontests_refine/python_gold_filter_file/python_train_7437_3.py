n,k,p = map(int,input().split())
l = list(map(int,input().split()))
even = list(filter(lambda x: x %2 ==0 ,l))
odd = list(filter(lambda x: x%2 == 1,l))

if (len(odd) - (k-p))% 2!=0:
    print("NO")
    exit(0)
ans = [[] for _ in range(k)]
for i in range(k-p):
    if odd:
        ans[i].append(odd.pop())
    else:
        print("NO")
        exit(0)

for i in range(k-p,k):
    if even:
        ans[i].append(even.pop())
    elif len(odd)>=2:
        ans[i].append(odd.pop())
        ans[i].append(odd.pop())
    else:
        print("NO")
        exit(0)

ans[0] += even + odd
print("YES")
for i in ans:
    print(len(i)," ".join(map(str,i)))
