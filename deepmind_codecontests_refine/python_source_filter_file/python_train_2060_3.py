n = list(input())
n = [int(i) for i in n]
n.reverse()
l = len(n)
ans = 0
for i in range(l-1):
    if (n[i]==5 and n[i+1]>=5) or n[i]>5:
        n[i+1] += 1
        ans += 10-n[i]
    else:
        ans += n[i]
ans += 9-n[-1] if n[-1]>5 else n[-1]
print(ans)
