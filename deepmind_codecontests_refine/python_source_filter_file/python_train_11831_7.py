s=input()
a=['a','e','i','o','u','0','2','4','6','8']
count=0
for i in range(len(s)):
    if s[i] in a:
        count+=1
print(count)