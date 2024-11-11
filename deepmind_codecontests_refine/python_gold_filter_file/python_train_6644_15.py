N=int(input())
N_sum=[]
for A in range(1,int(N/2)+1):
  B=N-A
  N_sum.append(sum(map(int,str(A)+str(B))))
print(min(N_sum))
