n = int(input())
s = list(input())
l = s.count("(")
r = s.count(")")
for i in range(n):
    if s[i]=="?":
        if 2*l < n:
            l+=1
            s[i]="("
        else:
            s[i]=")"
cnt=0
for i in range(n):
    cnt+=1 if s[i]=="(" else -1
    if i<n-1 and cnt==0:
        print(":(")
        exit()
    if i==n-1 and cnt>0:
        print(":(")
        exit()
print("".join(s))