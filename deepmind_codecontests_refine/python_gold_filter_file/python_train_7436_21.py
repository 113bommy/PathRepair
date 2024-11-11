n, k=input().split(" ")
n=int(n)
k=int(k)
s=input()
if k>n//2:
    i=k-1
    while i<n-1:
      print("RIGHT")
      i+=1
    for i in reversed(range(1, n)):
      print("PRINT {}".format(s[i]))
      print("LEFT")
    print("PRINT {}".format(s[0]))
else:
    i=k-1
    while i>0:
      print("LEFT")
      i-=1
    for i in range(n-1):
      print("PRINT {}".format(s[i]))
      print("RIGHT")
    print("PRINT {}".format(s[n-1]))