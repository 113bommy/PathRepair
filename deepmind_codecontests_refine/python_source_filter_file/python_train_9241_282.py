k=int(input())
s=str(input())
if k>len(s):
    print(s)
else:
    print(s[0:k]+'...')