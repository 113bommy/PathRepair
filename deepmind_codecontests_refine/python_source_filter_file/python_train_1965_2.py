import sys

ary=[]
for i in sys.stdin:
    ary.append(int(i))
m = max(ary)
prime=[1] * (m + 1)
prime[0] = prime[1] = 0
for i in range(2, int(m ** 0.5) + 1):
    if prime[i] == 1:
        for j in range(i*2, m + 1, i):
            prime[j] = 0
for i in range(len(ary)):
    print(sum(prime[:ary[i]]))