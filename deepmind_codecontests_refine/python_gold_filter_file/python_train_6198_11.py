n = int(input())
M = list(map(int, input().split()))
R = list(map(int, input().split()))
t = 0
num = max(max(M), max(R)) * 10000
for d in range(num):
    for i in range(n):
        if d % M[i] == R[i]:
            t += 1
            break
# print(t,num)
print(t / num)