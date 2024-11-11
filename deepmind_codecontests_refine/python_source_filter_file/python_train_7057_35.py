from collections import Counter
S=input()
K=int(input())
S_double = S*2
n = 0
if len(set(list(S)))==1:
    print(len(S)*K//2)
    exit()
while n< len(S_double)-1:
    if S_double[n] ==S_double[n+1]:
        S_double = S_double[:n+2]+' '+S_double[n+3:]
    n += 1
ans = Counter(S_double[:len(S)])[' '] + Counter(S_double[len(S):])[' ']*(K-1)
print(ans)
