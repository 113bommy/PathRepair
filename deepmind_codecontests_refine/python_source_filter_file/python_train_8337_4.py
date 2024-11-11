a,b = map(int,input().split())
st = input()
i = 1
out = 1
while i < len(st):
    if(st[i:len(st)]==st[:len(st)-i]):
        out = i
        break
    i+=1
print(st+st[len(st)-out:]*(b-1))
