n=int(input())
s=input().split()
maxi=0
for i in s:
    say=0
    for k in i:
        if k.isupper():
            say+=1
    if say>maxi:
        maxi=say
print(say)
