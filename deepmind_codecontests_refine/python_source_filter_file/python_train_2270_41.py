n,k=map(int,input().split())
s=list(input())
s[k]=chr(ord(s[k])+32)

print(*s,sep='')