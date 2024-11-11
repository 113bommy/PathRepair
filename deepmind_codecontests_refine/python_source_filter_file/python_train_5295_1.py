s=input()
l=len(s)
if s[0]==s[-1]:
    if l%2=1:
        print("First")
    else:
        print("Second")
else:
    if l%2=0:
        print("First")
    else:
        print("Second")