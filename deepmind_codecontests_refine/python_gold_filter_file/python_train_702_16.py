n = int(input())
A = list(map(int, input().split()))
q = int(input())
l = [0]*(10**5+10)
num = sum(A)
for i in A:
    l[i] = l[i] + 1


for i in range(q):
    b, c = map(int, input().split())
    num += (c-b)*l[b]
    l[c] += l[b]
    l[b] = 0
    print(num)
