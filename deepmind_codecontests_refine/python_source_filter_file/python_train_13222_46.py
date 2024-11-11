#shellSort(A, n)
n=int(input())
A=[int(input()) for i in range(n)]
cnt = 0
G=[1]
S=str(G[0])
#if 5<n<13:
t=n//2
#elif n<3000:
  #  t=n//9
#else:
  #  t=n//17
#Gt=[4, 9, 20, 46, 103, 233, 525, 1182,2660, 5985, 13467]
f=1.0
while f<t:
    f*=2.2
    f=int(f)
    G.insert(0,f)
  #  print (i)
    S=str(G[0])+" "+S
m=len(G)
print (m)
print(S)
for i in range(m):
    g=G[i]
    for j in range(g,n):
        v = A[j]
        k = j - g
        while k >= 0 and A[k] > v:
              A[k+g] = A[k]
              k = k - g
              cnt+=1
        A[k+g] = v 
print(cnt)
for i in range(n):
    print(A[i])