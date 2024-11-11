import bisect
S,T = input(),input()
lenS = len(S)
alp = [[]for i in range(26)]
for i in range(len(S)):
    alp[ord(S[i])-97].append(i)

if alp[ord(T[0])-97] == []:
    print(-1)
    exit()

l = [alp[ord(T[0])-97][0]]
for c in T[1:]:
    A = alp[ord(c)-97]
    if A == []:
        print(-1)
        exit()
    l.append(A[bisect.bisect_left(A,l[-1]+1)%len(A)])

ans = 0
for i in range(len(l)-1):
    if l[i] > l[i+1]:
        ans += 1
print(ans*lenS+l[-1]+1)