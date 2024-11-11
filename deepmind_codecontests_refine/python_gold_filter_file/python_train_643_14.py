a,b,c=map(int,input().split())
t=(b,c)
lst_left=[]
lst_right=[]
lst_up=[]
lst_down=[]
for i in range(a):
    n,m=map(int,input().split())
    if n>b:
        lst_right.append((n,m))
    if n<b:
        lst_left.append((n,m))
    if m>c:
        lst_up.append((n,m))
    if m<c:
        lst_down.append((n,m))
lst=[len(lst_left),len(lst_right),len(lst_up),len(lst_down)]
batman=max(lst)
print(batman)
if batman==lst[0]:
    b-=1
elif batman==lst[1]:
    b+=1
elif batman==lst[2]:
    c+=1
elif batman==lst[3]:
    c-=1
print(b,c)
