s=input()
l=len(s)
lowercase_count=0
uppercase_count=0
for item in s:
    if item.islower():
        lowercase_count+=1
    else:
        uppercase_count+=1
if lowercase_count>uppercase_count:
    s_new=s.lower()
else:
    s_new=s.upper()
print(s_new)