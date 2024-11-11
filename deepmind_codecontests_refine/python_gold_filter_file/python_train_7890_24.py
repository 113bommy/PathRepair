n=int(input())
s=list(input())
m=int(input())
for i in range(n):
    if s[i]!=s[m-1]:
        s[i]="*"
print("".join(s))