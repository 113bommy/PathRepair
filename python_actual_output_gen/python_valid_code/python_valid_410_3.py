n = int(input())
s='I hate'
a=' that i love'
b=' that i hate'
for i in range(1,n+1):
    if i%2!=0:
        s=s+a
    else:
        s=s+b
s=s+' it'
print(s)