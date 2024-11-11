N,K=map(int,input().split())
s={i+1 for i in range(N)}
t={}
for i in range(K):
  input()
  t|=set(map(int,input().split()))
print(len(s-t))