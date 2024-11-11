n=int(input())
s=input()
s2=input()
d=0
for i in range(n):
    d=d+min(abs(int(s[i])-int(s2[i])),(10-abs(int(s[i])-int(s2[i]))))
print(d)
    