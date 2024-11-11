s=input()
L=['a','u','i','o','e','0','2','4','6','8']
count=0
for i in range(len(s)):
  if s[i] in L:
    count=count+1
print(count)