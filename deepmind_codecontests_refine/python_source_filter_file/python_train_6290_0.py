def gt(x, y):
    if len(x)>len(y): return True
    if len(x)==len(y): return x>y
    return False

x = input()
r = 0
l = len(x)-1
while True:
    if l==0 or not gt(x[:l], x[l:]): break
    if x[l] == '0':
        l-=1
        continue
    x = x[:l]
    r+=1
    l-=1
r+=1
print(r)
