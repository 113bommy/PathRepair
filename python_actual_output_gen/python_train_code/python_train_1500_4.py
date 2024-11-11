n=bin(int(input()))[2:]
for i in range(len(n)):
  if int(n[i])==1:
    print(2**(len(n)-i-1), end=' ')