for _ in range(int(input())):
 n=int(input());arr=list(map(int,input().split()))
 ans=0;pos=0;neg=0
 for i in range(n):
  if arr[i]>0:pos+=arr[i]
  elif arr[i]<0:
   neg=abs(arr[i])
   if pos>=neg:pos=pos-neg
   elif neg>pos:ans+=(neg-pos);pos=0
   #print(ans)
 print(ans)
