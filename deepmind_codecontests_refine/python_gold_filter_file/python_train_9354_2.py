h,w=map(int,input().split())
disp=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
for i in range(h):
  arr=list(map(str,input().split()))
  for j in range(w):
    if arr[j]=='snuke':
      print(disp[j]+str(i+1))