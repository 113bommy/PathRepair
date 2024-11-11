s=input()
w=len(s)
q=-1
for i in range(w-2):
    for j in range(i+1,w-1):
        a,b,c= s[:i+1],s[i+1:j+1],s[j+1:]
        if len(a)==len(str(int(a))) and len(b)==len(str(int(b))) and len(c)==len(str(int(c))):
            if int(a)<=10**6 and int(b)<=10**6 and int(c)<=10**6:
                q=max(i,int(a)+int(b)+int(c))
print(q)