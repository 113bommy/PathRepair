MOD=10**9+7
N,K=map(int,input().split())
alist=list(map(int,input().split()))
alist.sort()
#print(alist)

inv_table = [0]+[1]
for i in range(2,K+3):
  inv_table.append(-(MOD//i)*inv_table[MOD%i]%MOD)

min_s,max_s=0,0
old_comb,new_comb=0,1
for i in range(K,N+1):
  #print(K,i,new_comb-old_comb)
  min_s+=(new_comb-old_comb)*alist[-1-(i-1)]
  min_s%=MOD
  max_s+=(new_comb-old_comb)*alist[i-1]
  max_s%=MOD
  
  old_comb=new_comb
  new_comb=old_comb*(i+1)*inv_table[i+1-K]%MOD
#print(min_s,max_s)

print((max_s-min_s)%MOD)