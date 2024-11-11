N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
if sum(A) < sum(B):
    print(-1)
    exit()
d = [A[i]-B[i] for i in range(N)]
print(d)
d.sort()
neg = 0
count = 0
for e in d:
    if e < 0:
        neg += e
        count += 1
        continue
    break
for e in d[::-1]:
    if neg >= 0:
        break
    neg += e 
    count += 1
print(count)