n=int(input())
s=list(input())
k=int(input())
for i in range(n):
    if s[i]!=s[k-1]:
        s[i]="*"
print("".join(s))