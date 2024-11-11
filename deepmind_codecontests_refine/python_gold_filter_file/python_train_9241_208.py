N=int(input())
l=input()
if len(l) > N:
   print(l[:N]+"...")
else:
   print(l)