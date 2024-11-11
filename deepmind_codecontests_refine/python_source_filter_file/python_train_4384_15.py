s=[int(i) for i in input().split(" ")]
w=s[0]
h=s[1]
k=s[2]
t=0
for i in range(k):
    t+=2*(w+h-2)
    w-=2
    h-=2
print(t)
