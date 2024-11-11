N=int(input())
A=list(int,input().split())
cnt=0

while all(i%2 == 0 for i in A):
  A = [i/2 for i in A]
  cnt+=1
print(cnt)
