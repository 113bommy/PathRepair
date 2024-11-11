#there would be two sets
#first set both (x1,y1)(x2,y2) in two differnt sorted half sets
#second set boty (x1,y1)(x2,y2) in same sets
n=int(input());m=2*n
arr=list(map(int,input().split()));arr=sorted(arr)
set1_ans=(arr[n-1]-arr[0])*(arr[2*n-1]-arr[n])
#print(set1_ans)
set2_ans=1e10
for i in range(1,n):
  a=(arr[2*n-1]-arr[0])*(arr[n-1+i]-arr[i])
  set2_ans=min(a,set2_ans)
print(min(set1_ans,set2_ans))
