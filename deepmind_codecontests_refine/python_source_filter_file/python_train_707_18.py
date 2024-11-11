K = int(input())

P = [n for n in range(1, 10)]
Q = [n for n in range(1, 10)]
for d in range(20):
    if d < 8:
        for m in range(10, 100):
            P.append(int(str(m)+"9"*d))
            Q.append(m//10+m%10+9*d)
    else:
        for m in range(100, 1000):
            P.append(int(str(m)+"9"*(d-1)))
            Q.append(sum([int(s) for s in str(m)])+9*(d-1))

L = len(P)
c = 0
for i, (p, q) in enumerate(zip(P, Q)):
    ok = True
    for j in range(i+1, L):
        np, nq = P[j], Q[j]
        if np*q < nq*p:
            ok = False
            break
    if ok:
        print(p)
        c += 1
    if c == K:
        break


"""
import matplotlib.pyplot as plt

A = []
B = []
for n in range(-1+10**10, 10**15, 10**10):
    m = sum([int(s) for s in str(n)])
    A.append(n)
    B.append(n/m)


plt.plot(A, B)
plt.show()
"""