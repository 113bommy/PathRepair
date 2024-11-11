t=int(input(""));
for i in range(t):
 n=int(input())
 a = list(map(int, input().split()))
 # print(max(a) + (sum(a) - max(a)) / (n - 1))
 d = 0
 for k in range(n-1):
  d+=a[k];
 print(a[len(a)-1]+d/(len(a)-1))