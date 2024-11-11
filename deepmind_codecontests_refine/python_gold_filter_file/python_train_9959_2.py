n,w = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]


minx = 0
maxx = w
if a[0]>=0:
    maxx = w - a[0]
else:
    minx = -a[0]

delta = a[0]

# print(minx,maxx)

dell = [delta]
for i in a[1:]:
    # print("minx",minx)
    delta += i
    dell.append(delta)
    if delta>w or delta<-w:
        maxx = -5
        minx = 0
        break
    if delta+maxx>w:
        maxx -= (delta+maxx-w)
    elif minx+delta<0:
        minx -= (minx +delta)
# print(maxx,minx)
# print(dell)
print(max(maxx-minx+1,0))