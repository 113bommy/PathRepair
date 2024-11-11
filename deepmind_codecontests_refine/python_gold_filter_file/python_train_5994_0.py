s=input()
a=s[::-1]
#print(a)
for i in range(len(s)):
    if a[i]==s[0]:
        d=a[:i+1][::-1]+a[i+1:][::-1]
        #print(a[:i+1][::-1]+a[i+1:][::-1])
        if d==s:
            #print(d)
            print(i+1)
            break
            
    