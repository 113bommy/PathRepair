s=input()
lst=['a','e','i','o','u','0','2','4','6','8']
cnt=0
for i in s:
    if i in lst:
        cnt+=1
print(cnt)