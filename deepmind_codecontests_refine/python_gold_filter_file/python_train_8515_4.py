N, K = list(map(int,input().split()))
S = input()

n = 1
c = []
if S[0]=='0': c.append(0)
for i in range(1,N):
    if S[i]!=S[i-1]:
        c.append(n)
        n=1
    else:
        n+=1
c.append(n)
if S[-1]=='0': c.append(0)

t = sum(c[:2*K+1])
m = t
for i in range(2*K+1, len(c), 2):
    t += c[i] + c[i+1] - c[i-(2*K+1)] - c[i+1-(2*K+1)]
    m = max(m,t)

print(m)
