n=int(input())
s=input()
s=list(s)
c=0
for i in range(2,n+1,2):
    if s[i-2:i]==["a","a"]:
        s[i-2]="b"
        c+=1
    elif s[i-2:i]==["b","b"]:
        s[i]="a"
        c+=1
print(c)
for i in s:
    print(i,end="")
print()