n,k=map(int,input().split())
s=list(input())
s[k-1]=chr(ord(s[k-1])+26)
print(''.join(s))