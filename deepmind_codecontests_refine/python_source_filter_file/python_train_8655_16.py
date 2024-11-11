k=input()
n=len(k)
a=0
for i in k:
    if i=="a":
        a+=1
if a>(a//2):
    print(n)
else:
    print((a*2)-1)