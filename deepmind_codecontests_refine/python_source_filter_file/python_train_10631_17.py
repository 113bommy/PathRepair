n = int(input())
A = [int(x) for x in input().split(' ')]

result = []

def add(i, x):
    result.append('1 {} {}'.format(i,x))
    for j in range(i+1):
        A[j] += x;

def mod(i, x):
    result.append('2 {} {}'.format(i,x))
    for j in range(i+1):
        A[j] %= x;

for i in reversed(range(n)):
    if A[i] % (n+1) > i + 1:
        add(i, (i + 1) + (n + 1) - A[i] % (n+1))
    elif A[i] % (n+1) < i + 1:
        add(i, (i + 1) - A[i] % (n+1))

if len(result) > 0:
    mod(n-1, n + 1)

print(len(result))

for s in result:
    print(s)