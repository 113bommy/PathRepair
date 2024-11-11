n=int(input())
s=''

while n>0:
    s=chr(n%26+96)+s
    n=n//26
print(s)