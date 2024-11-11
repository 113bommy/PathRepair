n = int(input())
for _ in range(n):
   h,n = map(int,input().split())
   P = list(map(int,input().split()))+[0,0]
   res = 0
   flg=0
   for i in range(n):
      if flg==1:
         flg=0
         continue
      # print('pi',P[i])
      if P[i]-1>=P[i+1]:
         P[i]=P[i+1]+1
         if P[i]-P[i+2]>2:
            P[i+1]=P[i+2]+1
            # print(P)
            res+=1
            # print('pi',P[i])
         else:
            flg=1
   print(res)