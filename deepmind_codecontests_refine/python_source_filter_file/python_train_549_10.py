vp = int(input())
vd = int(input())
t = int(input())
f = int(input())
c = int(input())
b=0
to=t
if vp>=vd:
    print(0)
    quit()
while True:
    tp=vd*to/(vd-vp)
    dp=tp*vp
    print(dp,c)
    if(dp>=c):
        print(b)
        quit()
    b+=1
    to=tp+dp/vd+f

print(b)
