n, m = map(int, input().split())
Xm = list(map(int, input().split()))
Xm.sort()
check = [Xm[i+1] - Xm[i] for i in range(m-1)]
check.sort()
print(sum(check[:-(n-1)]))
