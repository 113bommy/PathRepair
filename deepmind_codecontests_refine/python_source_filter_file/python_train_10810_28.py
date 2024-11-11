S = input()
l = S.__len__()
for i in range((l-1)//2,0,-1):
  if S[0:i-1] == S[i:i+i-1]:
    print(2*i)
