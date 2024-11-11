d,v = map(int,input().split())
list1 = [v]+[0]*(d-1)
ans = ''
for i in range(d):
    for e in range(d):
        ans += str(list1[e])
        if e == d-1:
            ans += '\n'
            list1.insert(0,list1.pop())
print(ans)