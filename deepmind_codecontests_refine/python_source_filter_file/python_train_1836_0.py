arr = ['C', 'C#', 'D', 'D#','E', 'F', 'F#', 'G', 'G#', 'A', 'B', 'H']
r = input()
r = r.split(' ')
a,b,c = r[0],r[1],r[1+1]
k = len(arr)
for i in range(k):
    if(a==arr[i]):
        A = i
    elif(b==arr[i]):
        B = i
    elif(c == arr[i]):
        C = i
l = [A,B,C]
l.sort()

q = l[1]-l[0]
e = l[1+1]-l[1]
flag = 1

if(q == 3 and e == 4):
    print('minor')
    flag = 0
elif(q == 4 and e == 3):
    print('major')
    flag = 0

q = 11 + 1 -l[1+1]+l[0]
e = l[1+1]-l[1]
if(q == 3 and e == 4):
    print('minor')
    flag = 0
elif(q == 4 and e == 3):
    print('major')
    flag = 0
else:
    q = 11 + 1 -l[1+1]+l[0]
    e = l[1]-l[0]
    if(q == 3 and e == 4):
        print('minor')
    elif(q == 4 and e == 3):
        print('major')
    else:
        if(flag):
            print("strange")
    