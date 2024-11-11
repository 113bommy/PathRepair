n=int(input());a=list(map(int,input().split()));ave=sum(a)//n;minn=0
for i in range(1,n):
  if abs(a[minn]-ave)>abs(a[i]-ave):minn=i
print(i)