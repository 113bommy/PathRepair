while True:
    s = input()
    if s == '_': 
        break

   m = int(input())
   for mi in range(m):
       h = int(input())
       s = s[h:] + s[:h]


   print(s)