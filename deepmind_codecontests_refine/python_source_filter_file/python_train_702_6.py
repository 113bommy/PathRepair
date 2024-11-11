n = int(input())
a = list(map(int, input().split()))
q = int(input())
A = [0]*100000

for i in a:
    A[i] += 1
    
ans = sum(a)

for i in range(q):
    b, c = map(int, input().split())
    ans = ans+((c-b)*(A[b]))
    print(ans)
    A[c] += A[b]
    A[b] = 0
