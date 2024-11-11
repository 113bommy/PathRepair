from sys import stdin,stdout
s=stdin.readline().rstrip()
if int(s)==0 or int(s)==1:
    stdout.write(s)
else:
    c=0
    f=0
    for i in range(1,len(s)):
        c+=1
        if s[i]=="1":
            f=1
    stdout.write(str(c//2+max(c%2,f))+"\n")