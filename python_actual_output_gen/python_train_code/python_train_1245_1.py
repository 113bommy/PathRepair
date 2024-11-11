num=int(input())
slimit = []
ans = 0
last = 0
olimit = 1
for i in range(num):
    a = list( map(int , input().split()) )
    if a[0] == 1:
        last = a[1]
        while len(slimit) and slimit[-1] < a[1]:
            ans+=1
            slimit.pop(-1)
    elif a[0] == 2:
        if olimit!=1:
            ans+=(1-olimit)
            olimit = 1
    elif a[0] == 3:
        slimit.append(a[1])
        while len(slimit)>0 and slimit[-1] < last:
            ans+=1
            slimit.pop(-1)
    elif a[0] == 4:
        ilimit = 1
    elif a[0] == 5:
        slimit = []
    elif a[0] == 6:
        olimit -= 1
print(ans)