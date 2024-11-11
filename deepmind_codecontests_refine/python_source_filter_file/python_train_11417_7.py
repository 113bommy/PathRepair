s=input()
if s!=s[::-1]:l=s
elif len(set(s))<2:l=0
else:l=len(s)-1
print(l)
