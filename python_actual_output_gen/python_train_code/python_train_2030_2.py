n=int(input())
s=input()
s2=input()
d=0
for i in range(n):
    d=d+min((int(s[i])-int(s2[i])),(9-(int(s[i])-int(s2[i]))))
print(d)
    