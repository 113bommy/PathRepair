for _ in range(int(input())):
   A, B, C, D = map(int, input().split())
   ans = [0,0,0,0]
   if (A+B)%2==1:
      ans[3] = 'Tidak'
      ans[2] = 'Tidak'
      ans[1] = 'Ya'
      ans[0] = 'Ya'
      if A==0:
         if D==0: ans[0] = 'Tidak'
      elif B==0:
         if C==0: ans[1] = 'Tidak'
   elif (A+B)%2==0:
      ans[3] = 'Ya'
      ans[2] = 'Ya'
      ans[1] = 'Tidak'
      ans[0] = 'Tidak'
      if D==0:
         if A==0: ans[3] = 'Tidak'
      elif C==0:
         if B==0: ans[2] = 'Tidak'
      

   print(*ans)
   
   
