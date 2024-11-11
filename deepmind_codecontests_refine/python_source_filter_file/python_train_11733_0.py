(N, Need) = list(map(int, input().split()))
s = input()
A = dict()
for i in range(97, 123):
    A[chr(i)] = 0

for i in A:
    A[i] = s.count(i)

LOL = 0
KEK = 0
while Need != 0:
    for i in (sorted(A.keys())):
        if A[i] > 0:
            if A[i] >= Need:
                A[i] -= Need
                LOL = Need
                KEK = i
                Need = 0

            else:
                Need -= A[i]
                A[i] = 0
            break

for i in range(len(s)):
    if s[i] == KEK:
        if LOL == 0:
            if A[s[i]] > 0:
                print(s[i], end='')
                A[s[i]] -=1
        else:
            LOL -= 1
    if A[s[i]] > 0:
        print(s[i], end='')
        A[s[i]] -= 1
