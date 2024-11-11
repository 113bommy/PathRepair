n,m = input().split()

ln = len(n)
lm = len(m)

if(ln>lm):
    m = m+"0"*(ln-lm)
else:
    n = "0"*(lm-ln)+n
ans = ['0']*(len(n)+1)
y1 = 0
for i in range(len(n)):
    x = str(int(m[i])+int(n[len(n)-i-1])+int(ans[len(n)-i]))
    if(len(x)==1):
        ans[len(n)-i]=x
    else:
        ans[len(n)-i]=x[1]
        ans[len(n)-i-1]=str(int(x[0])+int(ans[len(n)-i-1]))
a = ''
for i in range(len(ans)):
    a+=ans[i]
print(int(a))
        
        
