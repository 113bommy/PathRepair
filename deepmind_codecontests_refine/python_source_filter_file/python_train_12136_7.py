n = int(input())
s = list(input())
a = "";b=''
if n ==1 : print(s[0]);quit()
aa = s[0];del s[0]
bb = s[len(s)-1];del s[len(s)-1]
for i in reversed(range(len(s))):
    if n%2==0 :
        if i %2!=0 : a+=s[i]
        else : b+=s[i]
    else :
        if i %2==0 : a+=s[i]
        else : b+=s[i]
print(a+aa+b+bb)