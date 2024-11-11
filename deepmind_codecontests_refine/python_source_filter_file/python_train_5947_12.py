x=int(input())
s=input()
if s.count(s[0])==s.__len__():
    print("NO")
else:
    print("YES")
    for i in range(x):
        if not(s[i]==s[0]):
            print(s[i]+s[i-1])
            break